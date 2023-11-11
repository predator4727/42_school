/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PartCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 07:40:43 by oaydemir          #+#    #+#             */
/*   Updated: 2023/06/06 05:21:36 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "PartCommand.hpp"
#include "ClientConnection/ClientConnection.hpp"
#include "User/User.hpp"
#include "IRCServer/IRCServer.hpp"

PartCommand::PartCommand(ClientConnection &clientConnection, const ParsedMessage &parsedMessage)
	: Command(clientConnection, parsedMessage)
{
}

PartCommand::PartCommand(const PartCommand &source)
	: Command(source)
{
}

PartCommand::~PartCommand()
{
}

std::vector<std::string> split(const std::string &input, char delimiter)
{
	std::vector<std::string> result;
	std::string token;
	std::istringstream tokenStream(input);

	while (std::getline(tokenStream, token, delimiter))
	{
		result.push_back(token);
	}

	return result;
}

void PartCommand::execute()
{
	if (_parsedMessage.parameters.size() != 1 && _parsedMessage.parameters.size() != 2)
	{
		_clientConnection.sendMessage("461 " + _parsedMessage.command + " :Not enough parameters");
		return;
	}

	std::vector<std::string> channels = split(_parsedMessage.parameters[0], ',');
	std::string partMessage = _parsedMessage.parameters.size() == 2 ? _parsedMessage.parameters[1] : "";
	User &user = _clientConnection.getUser();
	IRCServer &server = _clientConnection.getServer();
	for (std::vector<std::string>::iterator it = channels.begin(); it != channels.end(); ++it)
	{
		std::string channelName = *it;
		if (channelName[0] != '#')
		{
			_clientConnection.sendMessage("403 " + _parsedMessage.parameters[0] + " :No such channel");
			return;
		}
		channelName = channelName.substr(1);
		try
		{
			Channel &channel = server.getChannelByName(channelName);
			channel.broadcastMessage(":" + user.getNickname() + " PART " + channelName + " :" + partMessage, user.getNickname());
			channel.removeUser(user.getNickname());
		}
		catch (NotFoundException &e)
		{
			_clientConnection.sendMessage("403 " + channelName + " :No such channel");
		}
	}
}
