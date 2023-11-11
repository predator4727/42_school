/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NoticeCommand.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 06:32:35 by oaydemir          #+#    #+#             */
/*   Updated: 2023/05/06 23:19:23 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "NoticeCommand.hpp"
#include "ClientConnection/ClientConnection.hpp"
#include "User/User.hpp"
#include "IRCServer/IRCServer.hpp"


NoticeCommand::NoticeCommand(ClientConnection& clientConnection, const ParsedMessage& parsedMessage)
    : Command(clientConnection, parsedMessage)
{
}

NoticeCommand::NoticeCommand(const NoticeCommand& source)
    : Command(source)
{
}

NoticeCommand::~NoticeCommand()
{
}

void NoticeCommand::execute()
{
	if (_parsedMessage.parameters.size() < 2)
	{
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

void	NoticeCommand::sendToUser(const std::string& nickname)
{
	try
	{
		std::cout << "Sending message to user:" << nickname << std::endl;
		ClientConnection& targetUserClientConnection = _clientConnection.getServer().getClientConnectionByNickname(nickname);
		std::string message = ":" + _clientConnection.getUser().getNickname() + " NOTICE " + targetUserClientConnection.getUser().getNickname() + " :" + _parsedMessage.parameters[1];
		targetUserClientConnection.sendMessage(message);
	}
	catch (NotFoundException& e)
	{
	}
}

void	NoticeCommand::sendToChannel(const std::string& channelName)
{
	try
	{
		std::cout << "Sending message to channel:" << channelName << std::endl;
		Channel& channel = _clientConnection.getServer().getChannelByName(channelName);
		if (!channel.hasUser((_clientConnection.getUser().getNickname())))
		{
			return;
		}
		std::string message = ":" + _clientConnection.getUser().getNickname() + " NOTICE #" + channelName + " :" + _parsedMessage.parameters[1];
		channel.broadcastMessage(message, _clientConnection.getUser().getNickname());
	}
	catch (NotFoundException& e)
	{
	}
}
