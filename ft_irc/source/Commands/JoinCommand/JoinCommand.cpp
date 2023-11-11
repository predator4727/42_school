/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JoinCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:01:57 by oaydemir          #+#    #+#             */
/*   Updated: 2023/06/02 00:26:10 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "JoinCommand.hpp"
#include "ClientConnection/ClientConnection.hpp"
#include "User/User.hpp"
#include "IRCServer/IRCServer.hpp"

JoinCommand::JoinCommand(ClientConnection &clientConnection, const ParsedMessage &parsedMessage)
	: Command(clientConnection, parsedMessage)
{
}

JoinCommand::JoinCommand(const JoinCommand &source)
	: Command(source)
{
}

JoinCommand::~JoinCommand()
{
}

void JoinCommand::execute()
{
	if (_clientConnection.getUser().getNickname().empty())
	{
		// Send the ERR_NOTREGISTERED message
		_clientConnection.sendMessage("431 " + _parsedMessage.command + " :Nickname not set");
		return;
	}

	if (_parsedMessage.parameters.size() != 1 && _parsedMessage.parameters.size() != 2)
	{
		_clientConnection.sendMessage("461 " + _parsedMessage.command + " :Not enough parameters");
		return;
	}

	if (_parsedMessage.parameters[0][0] != '#')
	{
		_clientConnection.sendMessage("403 " + _parsedMessage.parameters[0] + " :No such channel");
		return;
	}
	std::string channelName = _parsedMessage.parameters[0].substr(1);
	User &user = _clientConnection.getUser();
	IRCServer &server = _clientConnection.getServer();
	std::string password("");
	if (_parsedMessage.parameters.size() == 2)
	{
		password = _parsedMessage.parameters[1];
	}
	try
	{
		std::cout << "Joining channel: " << channelName << std::endl;
		Channel &channel = server.getChannelByName(channelName);
		if (channel.hasUser((_clientConnection.getUser().getNickname())))
		{
			_clientConnection.sendMessage("443 " + channelName + " :You are already on that channel");
			return;
		}
		channel.addUser(user.getNickname(), false, password);
	}
	catch (NotFoundException &e)
	{
		std::cout << "Creating channel: " << channelName << std::endl;
		Channel *newChannel = new Channel(server, channelName);
		server.addChannel(newChannel);
		newChannel->addUser(user.getNickname(), true);
	}
}
