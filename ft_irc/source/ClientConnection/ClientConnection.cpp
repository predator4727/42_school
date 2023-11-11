/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientConnection.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:25:15 by oaydemir          #+#    #+#             */
/*   Updated: 2023/06/07 23:22:23 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClientConnection.hpp"
#include <stdexcept>
#include <unistd.h>		// For read() and write()
#include <sys/socket.h> // For socket(), connect(), send(), and recv()
#include <iostream>
#include "Commands/NickCommand/NickCommand.hpp"
#include "Commands/UserCommand/UserCommand.hpp"
#include "Commands/PassCommand/PassCommand.hpp"
#include "Commands/QuitCommand/QuitCommand.hpp"
#include "Commands/JoinCommand/JoinCommand.hpp"
#include "Commands/PrivmsgCommand/PrivmsgCommand.hpp"
#include "Commands/NoticeCommand/NoticeCommand.hpp"
#include "Commands/PartCommand/PartCommand.hpp"
#include "Commands/OperatorCommands/OperatorCommands.hpp"

ClientConnection::ClientConnection(IRCServer &server, int socketFileDescriptor, User &user) : _server(server), _user(user), bytesRead(0), _socketFileDescriptor(socketFileDescriptor)
{
}

ClientConnection::~ClientConnection()
{
	closeConnection();
}

IRCServer &ClientConnection::getServer() const
{
	return _server;
}

int ClientConnection::getSocketFileDescriptor() const
{
	return _socketFileDescriptor;
}

User &ClientConnection::getUser() const
{
	return _user;
}

void ClientConnection::setUser(const User &user)
{
	_user = user;
}

bool ClientConnection::isCompleteMessage(const std::string &Message) const
{
	return Message.find("\r\n") != std::string::npos;
	// return (Message.find("\r\n") != std::string::npos || Message.find("\n") != std::string::npos);
}

void ClientConnection::handleIncomingMessage()
{
	MessageToolkit messageToolkit;

	bytesRead += recv(_socketFileDescriptor, &(buffer[bytesRead]), sizeof(buffer), 0);
	if (bytesRead > 0)
	{
		std::string receivedMessage(buffer, static_cast<std::size_t>(bytesRead));
		// If the message is complete, parse it and process it.
		if (!isCompleteMessage(receivedMessage))
		{
			return;
		}
		ParsedMessage parsedMessage = messageToolkit.parseIncomingMessage(receivedMessage);
		std::cout << "Parsed message: " << parsedMessage.command << std::endl;
		// reset buffer now that we have complete message
		bytesRead = 0;
		std::memset(buffer, 0, sizeof(buffer));
		// Process the parsed message and execute the appropriate command.
		Command *command = createCommand(parsedMessage);
		if (command)
		{
			command->execute();
			delete command;
		}
	}
	else
	{
		// Handle client disconnection
		std::cout << "Client "<< _user.getNickname() << " disconnected abruptly" << std::endl;

		_server.removeUser(getUser());
		_server.removeClientConnection(*this);
		int targetFd = _socketFileDescriptor; // The fd you want to remove.
		closeConnection();
		for (std::vector<pollfd>::iterator it = _server.pollFds.begin(); it != _server.pollFds.end(); ++it)
		{
			if (it->fd == targetFd)
			{
				_server.pollFds.erase(it);
				break; // Assuming you only want to remove the first matching fd.
			}
		}
		delete &(getUser());
		delete this;
	}
}

void ClientConnection::sendMessage(std::string message) const
{
	message += "\r\n";
	ssize_t bytesSent = send(_socketFileDescriptor, message.c_str(), message.length(), 0);
	if (bytesSent == -1)
	{
		throw std::runtime_error("Error sending message");
	}
}

void ClientConnection::closeConnection()
{
	if (_socketFileDescriptor != -1)
	{
		if (close(_socketFileDescriptor) == -1)
		{
			throw std::runtime_error("Error closing socket");
		}
		_socketFileDescriptor = -1;
	}
}

Command *ClientConnection::createCommand(const ParsedMessage &parsedMessage)
{
	if (parsedMessage.command == "PASS")
	{
		return new PassCommand(*this, parsedMessage);
	}
	else if (parsedMessage.command == "NICK")
	{
		return new NickCommand(*this, parsedMessage);
	}
	else if (parsedMessage.command == "USER")
	{
		return new UserCommand(*this, parsedMessage);
	}
	else if (parsedMessage.command == "JOIN")
	{
		return new JoinCommand(*this, parsedMessage);
	}
	else if (parsedMessage.command == "PRIVMSG")
	{
		return new PrivmsgCommand(*this, parsedMessage);
	}
	else if (parsedMessage.command == "NOTICE")
	{
		return new NoticeCommand(*this, parsedMessage);
	}
	else if (parsedMessage.command == "PART")
	{
		return new PartCommand(*this, parsedMessage);
	}
	else if (parsedMessage.command == "MODE" || parsedMessage.command == "TOPIC" || parsedMessage.command == "INVITE" || parsedMessage.command == "KICK")
	{
		return new OperatorCommands(*this, parsedMessage);
	}
	else if (parsedMessage.command == "QUIT")
	{
		return new QuitCommand(*this, parsedMessage);
	}
	else if (parsedMessage.command == "PING")
	{
		sendMessage("PONG " + parsedMessage.parameters[0]);
	}
	else if (parsedMessage.command != "PONG")
	{
		sendMessage("421 " + parsedMessage.command + " :Unknown command");
	}
	return NULL;
}
