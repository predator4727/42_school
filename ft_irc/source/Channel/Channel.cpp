/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:25:28 by oaydemir          #+#    #+#             */
/*   Updated: 2023/06/08 00:09:22 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"
#include "ClientConnection/ClientConnection.hpp"
#include <iostream>
#include "IRCServer/IRCServer.hpp"

Channel::Channel(IRCServer &ircServer, const std::string name) : _name(name), _ircServer(ircServer), _topic(""), _isTopicLocked(false), _isInviteOnly(false), _maxUserCount(0), _password("")
{
	std::cout << "Channel " << _name << " created" << std::endl;
}

Channel::~Channel()
{
}

std::string Channel::getName() const
{
	return _name;
}

void Channel::addUser(std::string user, bool isOperator, std::string password)
{
	ClientConnection &clientConnection = _ircServer.getClientConnectionByNickname(user);
	if (_maxUserCount != 0 && _users.size() >= _maxUserCount)
	{
		clientConnection.sendMessage("471 " + _ircServer.getUserByNickname(user).getNickname() + " " + _name + " :Cannot join channel (+l)");
		return;
	}
	if (_password != password)
	{
		clientConnection.sendMessage("475 " + _ircServer.getUserByNickname(user).getNickname() + " " + _name + " :Cannot join channel (+k)");
		return;
	}
	if (_isInviteOnly && std::find(_invitedUsers.begin(), _invitedUsers.end(), user) == _invitedUsers.end())
	{
		clientConnection.sendMessage("473 " + _ircServer.getUserByNickname(user).getNickname() + " " + _name + " :Cannot join channel (+i)");
		return;
	}
	_users[user] = isOperator;
	clientConnection.sendMessage("332 " + _ircServer.getUserByNickname(user).getNickname() + " " + getName() + " :" + getTopic());
}

void Channel::removeUser(std::string user)
{
	_users.erase(user);
}

bool Channel::hasUser(std::string user) const
{
	return _users.find(user) != _users.end();
}

void Channel::setOperator(std::string sourceUser, std::string targetUser, bool candidateIsOperator)
{
	if (isOperator(sourceUser))
	{
		_users[targetUser] = candidateIsOperator;
	}
	else
	{
		ClientConnection &clientConnection = _ircServer.getClientConnectionByNickname(sourceUser);
		clientConnection.sendMessage("482 " + _ircServer.getUserByNickname(sourceUser).getNickname() + " " + _name + " :You're not channel operator");
	}
}

bool Channel::isOperator(std::string user) const
{
	std::map<std::string, bool>::const_iterator it = _users.find(user);
	if (it == _users.end())
	{
		return false;
	}
	return it->second;
}

bool Channel::isInviteOnly() const
{
	return _isInviteOnly;
}

void Channel::setIsInviteOnly(std::string sourceUser, bool candidateIsInviteOnly)
{
	if (isOperator(sourceUser))
	{
		_isInviteOnly = candidateIsInviteOnly;
	}
	else
	{
		ClientConnection &clientConnection = _ircServer.getClientConnectionByNickname(sourceUser);
		clientConnection.sendMessage("482 " + _ircServer.getUserByNickname(sourceUser).getNickname() + " " + _name + " :You're not channel operator");
	}
}

bool Channel::isInvited(std::string user) const
{
	std::vector<std::string>::const_iterator it = _invitedUsers.begin();
	for (; it != _invitedUsers.end(); ++it)
	{
		if (*it == user)
		{
			return true;
		}
	}
	return false;
}

void Channel::inviteUser(std::string sourceUser, std::string targetUser)
{
	if (isOperator(sourceUser))
	{
		_invitedUsers.push_back(targetUser);
	}
	else
	{
		ClientConnection &clientConnection = _ircServer.getClientConnectionByNickname(sourceUser);
		clientConnection.sendMessage("482 " + _ircServer.getUserByNickname(sourceUser).getNickname() + " " + _name + " :You're not channel operator");
	}
}

bool Channel::isTopicLocked() const
{
	return _isTopicLocked;
}

void Channel::setIsTopicLocked(std::string sourceUser, bool candidateIsTopicLocked)
{
	if (isOperator(sourceUser))
	{
		_isTopicLocked = candidateIsTopicLocked;
	}
	else
	{
		ClientConnection &clientConnection = _ircServer.getClientConnectionByNickname(sourceUser);
		clientConnection.sendMessage("482 " + _ircServer.getUserByNickname(sourceUser).getNickname() + " " + _name + " :You're not channel operator");
	}
}

std::string Channel::getTopic() const
{
	return _topic;
}

void Channel::setTopic(std::string sourceUser, const std::string &topic)
{
	if (!_isTopicLocked || isOperator(sourceUser))
	{
		_topic = topic;
	}
	else
	{
		ClientConnection &clientConnection = _ircServer.getClientConnectionByNickname(sourceUser);
		clientConnection.sendMessage("482 " + _ircServer.getUserByNickname(sourceUser).getNickname() + " " + _name + " :You're not channel operator");
	}
}

std::string Channel::getPassword() const
{
	return _password;
}

void Channel::setPassword(std::string sourceUser, const std::string &password)
{
	if (isOperator(sourceUser))
	{
		_password = password;
	}
	else
	{
		ClientConnection &clientConnection = _ircServer.getClientConnectionByNickname(sourceUser);
		clientConnection.sendMessage("482 " + _ircServer.getUserByNickname(sourceUser).getNickname() + " " + _name + " :You're not channel operator");
	}
}

unsigned int Channel::getMaxUserCount() const
{
	return _maxUserCount;
}

void Channel::setMaxUserCount(std::string sourceUser, unsigned int maxUserCount)
{
	if (isOperator(sourceUser))
	{
		_maxUserCount = maxUserCount;
	}
	else
	{
		ClientConnection &clientConnection = _ircServer.getClientConnectionByNickname(sourceUser);
		clientConnection.sendMessage("482 " + _ircServer.getUserByNickname(sourceUser).getNickname() + " " + _name + " :You're not channel operator");
	}
}

unsigned int Channel::getUserCount() const
{
	return _users.size();
}

void Channel::broadcastMessage(const std::string &message, std::string sender)
{
	std::map<std::string, bool>::iterator it;
	for (it = _users.begin(); it != _users.end(); ++it)
	{
		User &client = _ircServer.getUserByNickname(it->first);
		ClientConnection &clientConnection = _ircServer.getClientConnectionByUser(client);
		std::cout << "Sending message to " << client.getNickname() << std::endl;
		if (it->first != sender)
		{
			clientConnection.sendMessage(message);
		}
	}
}

void Channel::kickUser(std::string user, std::string sender, const std::string &reason)
{
	if (!isOperator(sender))
	{
		ClientConnection &clientConnection = _ircServer.getClientConnectionByNickname(sender);
		clientConnection.sendMessage("482 " + sender + " " + _name + " :You're not channel operator");
		return;
	}
	std::map<std::string, bool>::iterator it = _users.find(user);
	if (it != _users.end())
	{
		User &client = _ircServer.getUserByNickname(it->first);
		ClientConnection &clientConnection = _ircServer.getClientConnectionByUser(client);
		clientConnection.sendMessage(":" + sender + " KICK " + _name + " " + client.getNickname() + " :" + reason);
		removeUser(it->first);
	}
}
