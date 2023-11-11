/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperatorCommands.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 07:57:30 by oaydemir          #+#    #+#             */
/*   Updated: 2023/06/02 00:29:51 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "OperatorCommands.hpp"
#include "ClientConnection/ClientConnection.hpp"
#include "User/User.hpp"
#include "IRCServer/IRCServer.hpp"

OperatorCommands::OperatorCommands(ClientConnection& clientConnection, const ParsedMessage &parsedMessage)
	: Command(clientConnection, parsedMessage)
{
}

OperatorCommands::OperatorCommands(const OperatorCommands &source)
	: Command(source)
{
}

OperatorCommands::~OperatorCommands()
{
}

void OperatorCommands::execute()
{
	if (_parsedMessage.command == "MODE")
	{
		_mode();
	}
	else if (_parsedMessage.command == "TOPIC")
	{
		_topic();
	}
	else if (_parsedMessage.command == "INVITE")
	{
		_invite();
	}
	else if (_parsedMessage.command == "KICK")
	{
		_kick();
	}
}

void OperatorCommands::_mode()
{
	if (_parsedMessage.parameters.size() < 2)
	{
		_clientConnection.sendMessage("461 " + _parsedMessage.command + " :Not enough parameters");
		return;
	}
	if (_parsedMessage.parameters[0][0] != '#')
	{
		_clientConnection.sendMessage("403 " + _parsedMessage.parameters[0] + " :No such channel");
		return;
	}
	if (_parsedMessage.parameters[1][0] != '+' && _parsedMessage.parameters[1][0] != '-')
	{
		_clientConnection.sendMessage("461 " + _parsedMessage.command + " :Not enough parameters");
		return;
	}
	if (_parsedMessage.parameters[1].size() < 2)
	{
		_clientConnection.sendMessage("461 " + _parsedMessage.command + " :Not enough parameters");
		return;
	}
	if (_parsedMessage.parameters[1][1] != 'o' && _parsedMessage.parameters[1][1] != 't' && _parsedMessage.parameters[1][1] != 'k' && _parsedMessage.parameters[1][1] != 'l' && _parsedMessage.parameters[1][1] != 'i')
	{
		_clientConnection.sendMessage("472 " + std::string(1, _parsedMessage.parameters[1][1]) + " :is unknown mode char to me");
		return;
	}

	Channel &channel = _clientConnection.getServer().getChannelByName(_parsedMessage.parameters[0].substr(1));
	if (!channel.isOperator(_clientConnection.getUser().getNickname()))
	{
		_clientConnection.sendMessage("482 " + _parsedMessage.parameters[0] + " :You're not channel operator");
		return;
	}

	try
	{

		if (_parsedMessage.parameters[1][0] == '+')
		{
			if (_parsedMessage.parameters[1][1] == 'o')
			{
				if (_parsedMessage.parameters.size() < 3)
				{
					_clientConnection.sendMessage("461 " + _parsedMessage.command + " :Not enough parameters");
					return;
				}
				User &user = _clientConnection.getServer().getUserByNickname(_parsedMessage.parameters[2]);
				channel.setOperator(_clientConnection.getUser().getNickname(), user.getNickname(), true);
			}
			else if (_parsedMessage.parameters[1][1] == 't')
				channel.setIsTopicLocked(_clientConnection.getUser().getNickname(), true);
			else if (_parsedMessage.parameters[1][1] == 'k')
			{
				if (_parsedMessage.parameters.size() < 3)
				{
					_clientConnection.sendMessage("461 " + _parsedMessage.command + " :Not enough parameters");
					return;
				}
				channel.setPassword(_clientConnection.getUser().getNickname(), _parsedMessage.parameters[2]);
			}
			else if (_parsedMessage.parameters[1][1] == 'l')
			{
				if (_parsedMessage.parameters.size() < 3)
				{
					_clientConnection.sendMessage("461 " + _parsedMessage.command + " :Not enough parameters");
					return;
				}
				unsigned int maxUserCount = std::atoi(_parsedMessage.parameters[2].c_str());
				if (maxUserCount < channel.getUserCount())
				{
					_clientConnection.sendMessage("405 " + _parsedMessage.parameters[2] + " :Cannot set limit lower than current user count");
					return;
				}
				channel.setMaxUserCount(_clientConnection.getUser().getNickname(), maxUserCount);
			}
			else if (_parsedMessage.parameters[1][1] == 'i')
				channel.setIsInviteOnly(_clientConnection.getUser().getNickname(), true);
		}
		else // if (_parsedMessage.parameters[1][0] == '-')
		{
			if (_parsedMessage.parameters[1][1] == 'o')
			{
				if (_parsedMessage.parameters.size() < 3)
				{
					_clientConnection.sendMessage("461 " + _parsedMessage.command + " :Not enough parameters");
					return;
				}
				User &user = _clientConnection.getServer().getUserByNickname(_parsedMessage.parameters[2]);
				channel.setOperator(_clientConnection.getUser().getNickname(), user.getNickname(), false);
			}
			else if (_parsedMessage.parameters[1][1] == 't')
				channel.setIsTopicLocked(_clientConnection.getUser().getNickname(), false);
			else if (_parsedMessage.parameters[1][1] == 'k')
				channel.setPassword(_clientConnection.getUser().getNickname(), "");
			else if (_parsedMessage.parameters[1][1] == 'l')
				channel.setMaxUserCount(_clientConnection.getUser().getNickname(), 0);
			else if (_parsedMessage.parameters[1][1] == 'i')
				channel.setIsInviteOnly(_clientConnection.getUser().getNickname(), false);
		}
	}
	catch (NotFoundException &e)
	{
		_clientConnection.sendMessage("401 " + _parsedMessage.parameters[2] + " :No such nick/channel");
		return;
	}
}

void OperatorCommands::_topic()
{
	if (_parsedMessage.parameters.size() < 1)
	{
		_clientConnection.sendMessage("461 " + _parsedMessage.command + " :Not enough parameters");
		return;
	}
	if (_parsedMessage.parameters[0][0] != '#')
	{
		_clientConnection.sendMessage("403 " + _parsedMessage.parameters[0] + " :No such channel");
		return;
	}
	Channel &channel = _clientConnection.getServer().getChannelByName(_parsedMessage.parameters[0].substr(1));
	if (_parsedMessage.parameters.size() == 1)
	{
		if (channel.getTopic().empty())
			_clientConnection.sendMessage("331 " + _parsedMessage.parameters[0] + " :No topic is set");
		else
			_clientConnection.sendMessage("332 " + _parsedMessage.parameters[0] + " :" + channel.getTopic());
	}
	else
	{
		channel.setTopic(_clientConnection.getUser().getNickname(), _parsedMessage.parameters[1]);
	}
}

void OperatorCommands::_invite()
{
	if (_parsedMessage.parameters.size() < 2)
	{
		_clientConnection.sendMessage("461 " + _parsedMessage.command + " :Not enough parameters");
		return;
	}
	if (_parsedMessage.parameters[0][0] != '#')
	{
		_clientConnection.sendMessage("403 " + _parsedMessage.parameters[0] + " :No such channel");
		return;
	}
	try
	{
		Channel &channel = _clientConnection.getServer().getChannelByName(_parsedMessage.parameters[0].substr(1));
		User &user = _clientConnection.getServer().getUserByNickname(_parsedMessage.parameters[1]);
		channel.inviteUser(_clientConnection.getUser().getNickname(), user.getNickname());
	}
	catch (NotFoundException &e)
	{
		_clientConnection.sendMessage("401 " + _parsedMessage.parameters[1] + " :No such nick/channel");
		return;
	}
}


void OperatorCommands::_kick()
{
	if (_parsedMessage.parameters.size() < 2)
	{
		_clientConnection.sendMessage("461 " + _parsedMessage.command + " :Not enough parameters");
		return;
	}
	if (_parsedMessage.parameters[0][0] != '#')
	{
		_clientConnection.sendMessage("403 " + _parsedMessage.parameters[0] + " :No such channel");
		return;
	}
	try 
	{
		Channel &channel = _clientConnection.getServer().getChannelByName(_parsedMessage.parameters[0].substr(1));
		if (!channel.isOperator(_clientConnection.getUser().getNickname()))
		{
			std::cout << _clientConnection.getUser().getNickname() << " is not channel operator" << std::endl;
			_clientConnection.sendMessage("482 " + _parsedMessage.parameters[0] + " :You're not channel operator");
			return;
		}
		try
		{
			User &user = _clientConnection.getServer().getUserByNickname(_parsedMessage.parameters[1]);
			std::string reason = "";
			if (_parsedMessage.parameters.size() > 2)
				reason = _parsedMessage.parameters[2];
			channel.kickUser(user.getNickname(), _clientConnection.getUser().getNickname(), reason);
		}
		catch (NotFoundException &e)
		{
			_clientConnection.sendMessage("401 " + _parsedMessage.parameters[1] + " :No such nick/channel");
			return;
		}
	}
	catch (NotFoundException& e)
	{
		_clientConnection.sendMessage("401 " + _parsedMessage.parameters[1] + " :No such nick/channel");
		return;
	}
}