/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrivmsgCommand.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 06:32:35 by oaydemir          #+#    #+#             */
/*   Updated: 2023/06/02 00:24:16 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PrivmsgCommand.hpp"
#include "ClientConnection/ClientConnection.hpp"
#include "User/User.hpp"
#include "IRCServer/IRCServer.hpp"


PrivmsgCommand::PrivmsgCommand(ClientConnection& clientConnection, const ParsedMessage& parsedMessage)
    : Command(clientConnection, parsedMessage)
{
}

PrivmsgCommand::PrivmsgCommand(const PrivmsgCommand& source)
    : Command(source)
{
}

PrivmsgCommand::~PrivmsgCommand()
{
}

void PrivmsgCommand::execute()
{
	if (_parsedMessage.parameters.size() < 2)
	{
		_clientConnection.sendMessage("461 " + _parsedMessage.command + " :Not enough parameters");
		return;
	}
	
	std::string messageTarget = _parsedMessage.parameters[0];
	if (messageTarget[0] == '#')
	{
		sendToChannel(messageTarget.substr(1));
	}
	else
	{
		sendToUser(messageTarget);
	}
}

void	PrivmsgCommand::sendToUser(const std::string& nickname)
{
	try
	{
		std::cout << "Sending message to user:" << nickname << std::endl;
		ClientConnection& targetUserClientConnection = _clientConnection.getServer().getClientConnectionByNickname(nickname);
		std::string message = ":" + _clientConnection.getUser().getNickname() + " PRIVMSG " + targetUserClientConnection.getUser().getNickname() + " :" + _parsedMessage.parameters[1];
		targetUserClientConnection.sendMessage(message);
	}
	catch (NotFoundException& e)
	{
		// give the ERR_NOSUCHNICK error code which is 401
		_clientConnection.sendMessage("401 " + nickname + " :No such nick/channel");
	}
}

void	PrivmsgCommand::sendToChannel(const std::string& channelName)
{
	try
	{
		std::cout << "Sending message to channel:" << channelName << std::endl;
		Channel& channel = _clientConnection.getServer().getChannelByName(channelName);
		if (!channel.hasUser(_clientConnection.getUser().getNickname()))
		{
			std::cout << "User" << _clientConnection.getUser().getNickname() << "is not in the channel" << std::endl;
			_clientConnection.sendMessage("404 " + channelName + " :Cannot send to channel");
			return;
		}
		std::string message = ":" + _clientConnection.getUser().getNickname() + " PRIVMSG #" + channelName + " :" + _parsedMessage.parameters[1];
		channel.broadcastMessage(message, _clientConnection.getUser().getNickname());
	}
	catch (NotFoundException& e)
	{
		_clientConnection.sendMessage("403 " + channelName + " :No such channel");
	}
}
