/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IRCServer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:26:25 by oaydemir          #+#    #+#             */
/*   Updated: 2023/06/07 23:47:05 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"
#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>
#include <fcntl.h>
#include <pthread.h>

IRCServer::IRCServer(int port, const std::string &password)
	: _socketFileDescriptor(-1), _password(password)
{
	// Create a socket
	_socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
	if (_socketFileDescriptor == -1)
	{
		throw std::runtime_error("Could not create socket");
	}

	// Bind the socket to the given port
	sockaddr_in serverAddress;
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(port);
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	int enableReuseAddr = 1;
	if (setsockopt(_socketFileDescriptor, SOL_SOCKET, SO_REUSEADDR, &enableReuseAddr, sizeof(int)) == -1)
	{
		throw std::runtime_error("Could not set SO_REUSEADDR socket option");
	}
	if (bind(_socketFileDescriptor, (sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
	{
		throw std::runtime_error("Could not bind socket");
	}

	// Listen for incoming connections
	if (listen(_socketFileDescriptor, SOMAXCONN) == -1)
	{
		throw std::runtime_error("Could not listen on socket");
	}
}

IRCServer::~IRCServer()
{
	if (_socketFileDescriptor != -1)
	{
		close(_socketFileDescriptor);
	}
	std::vector<ClientConnection *>::iterator iter_clientConnection;
	for (iter_clientConnection = _clientConnections.begin(); iter_clientConnection != _clientConnections.end(); ++iter_clientConnection)
	{
		delete *iter_clientConnection;
	}
	std::vector<User *>::iterator iter_user;
	for (iter_user = _users.begin(); iter_user != _users.end(); ++iter_user)
	{
		delete *iter_user;
	}
	std::vector<Channel *>::iterator iter_channel;
	for (iter_channel = _channels.begin(); iter_channel != _channels.end(); ++iter_channel)
	{
		delete *iter_channel;
	}
}

void *sendPingToAllClientsThread(void *arg)
{
	IRCServer *server = static_cast<IRCServer *>(arg);
	while (true)
	{
		server->sendPingToAllClients();
		sleep(5); // wait for 5 seconds
	}
	return NULL;
}

void IRCServer::run()
{
	// Add the main server socket to the pollFds vector
	pollfd serverPollFd;
	serverPollFd.fd = _socketFileDescriptor;
	serverPollFd.events = POLLIN;
	serverPollFd.revents = 0;
	pollFds.push_back(serverPollFd);

	std::cout << "Server initialized" << std::endl;
	// system("say -v Lekha Welcome to My I.R.C. Server! This is a private I.R.C. network for chatting and socializing. We hope you enjoy your time here.");
	// system("say -v Lekha Welcome, youve landed on our I.R.C. Server! We value light-speed communication and respect. Enjoy your interstellar journey.");

	pthread_t pingThread;
	if (pthread_create(&pingThread, NULL, &sendPingToAllClientsThread, this) != 0)
	{
		throw std::runtime_error("Could not create ping thread");
	}
	pthread_detach(pingThread);
	
	while (true)
	{
		int pollResult = poll(&pollFds[0], pollFds.size(), -1);
		if (pollResult == -1)
		{
			std::cerr << "Error polling sockets" << std::endl;
			continue;
		}
		// Check if new data is coming in
		if (pollFds[0].revents & POLLIN)
		{
			// This block is responsible for handling new client connections
			sockaddr_in clientAddress;
			socklen_t clientAddressSize = sizeof(clientAddress);
			int clientSocket = accept(_socketFileDescriptor, (sockaddr *)&clientAddress, &clientAddressSize);
			if (clientSocket == -1)
			{
				std::cerr << "Error accepting client connection" << std::endl;
				continue;
			}
			if (fcntl(clientSocket, F_SETFL, O_NONBLOCK) == -1)
			{
				std::cerr << "Error setting socket to non-blocking mode" << std::endl;
				continue;
			}
			// Create a new User and ClientConnection for the accepted connection
			// We should free these later
			User *newUser = new User();
			ClientConnection *newClientConnection = new ClientConnection(*this, clientSocket, *newUser);
			addUser(*newUser);
			addClientConnection(*newClientConnection);

			// Add the new client socket to the pollFds vector
			pollfd clientPollFd;
			clientPollFd.fd = clientSocket;
			clientPollFd.events = POLLIN;
			clientPollFd.revents = 0;
			pollFds.push_back(clientPollFd);
		}
		//  Check for incoming data from client connections
		for (size_t i = 1; i < pollFds.size(); ++i)
		{
			// check if data is coming in through the client socket
			if (pollFds[i].revents & POLLIN)
			{
				ClientConnection &clientConnection = getClientConnectionBySocket(pollFds[i].fd);
				clientConnection.handleIncomingMessage();
			}
		}
	}
}

void IRCServer::addClientConnection(ClientConnection &clientConnection)
{
	_clientConnections.push_back(&clientConnection);
}

void IRCServer::removeClientConnection(ClientConnection &clientConnection)
{
	_clientConnections.erase(std::remove(_clientConnections.begin(), _clientConnections.end(), &clientConnection), _clientConnections.end());
}

void IRCServer::addUser(User &user)
{
	_users.push_back(&user);
}

void IRCServer::removeUser(User &user)
{
	_users.erase(std::remove(_users.begin(), _users.end(), &user), _users.end());
}

void IRCServer::addChannel(Channel *channel)
{
	_channels.push_back(channel);
}

void IRCServer::removeChannel(Channel *channel)
{
	_channels.erase(std::remove(_channels.begin(), _channels.end(), channel), _channels.end());
}

bool IRCServer::isNicknameAvailable(const std::string &nickname) const
{
	for (std::vector<User *>::const_iterator it = _users.begin(); it != _users.end(); ++it)
	{
		User *user = *it;
		if (user->getNickname() == nickname)
		{
			return false;
		}
	}
	return true;
}

ClientConnection &IRCServer::getClientConnectionByUser(const User &user)
{
	for (std::vector<ClientConnection *>::const_iterator it = _clientConnections.begin(); it != _clientConnections.end(); ++it)
	{
		ClientConnection *clientConnection = *it;
		if (&clientConnection->getUser() == &user)
		{
			return *clientConnection;
		}
	}
	std::cout << "ClientConnection not found for the specified user.";
	throw NotFoundException("ClientConnection not found for the specified user.");
}

User &IRCServer::getUserByClientConnection(const ClientConnection &clientConnection)
{
	for (std::vector<User *>::const_iterator it = _users.begin(); it != _users.end(); ++it)
	{
		User *user = *it;
		if (user == &clientConnection.getUser())
		{
			return *user;
		}
	}
	throw NotFoundException("User not found for the specified client connection.");
}

Channel &IRCServer::getChannelByName(const std::string &channelName)
{
	for (std::vector<Channel *>::iterator it = _channels.begin(); it != _channels.end(); ++it)
	{
		Channel *channel = *it;
		if (channel->getName() == channelName)
		{
			return *channel;
		}
	}

	throw NotFoundException("Channel not found for the specified name.");
}

Channel &IRCServer::getChannelByName(const std::string &channelName) const
{
	for (std::vector<Channel *>::const_iterator it = _channels.begin(); it != _channels.end(); ++it)
	{
		Channel *channel = *it;
		if (channel->getName() == channelName)
		{
			return *channel;
		}
	}
	std::cout << "Channel not found\n";
	throw NotFoundException("Channel not found for the specified name.");
}

User &IRCServer::getUserByNickname(const std::string &nickname)
{
	for (std::vector<User *>::const_iterator it = _users.begin(); it != _users.end(); ++it)
	{
		User *user = *it;
		if (user->getNickname() == nickname)
		{
			return *user;
		}
	}
	std::cout << "User not found for the specified nickname.";
	throw NotFoundException("User not found for the specified nickname.");
}

User &IRCServer::getUserByNickname(const std::string &nickname) const
{
	for (std::vector<User *>::const_iterator it = _users.begin(); it != _users.end(); ++it)
	{
		User *user = *it;
		if (user->getNickname() == nickname)
		{
			return *user;
		}
	}
	throw NotFoundException("User not found for the specified nickname.");
}

ClientConnection &IRCServer::getClientConnectionByNickname(const std::string &nickname)
{
	for (std::vector<ClientConnection *>::const_iterator it = _clientConnections.begin(); it != _clientConnections.end(); ++it)
	{
		ClientConnection *clientConnection = *it;
		if (clientConnection->getUser().getNickname() == nickname)
		{
			return *clientConnection;
		}
	}
	throw NotFoundException("ClientConnection not found for the specified nickname.");
}

ClientConnection &IRCServer::getClientConnectionByNickname(const std::string &nickname) const
{
	for (std::vector<ClientConnection *>::const_iterator it = _clientConnections.begin(); it != _clientConnections.end(); ++it)
	{
		ClientConnection *clientConnection = *it;
		if (clientConnection->getUser().getNickname() == nickname)
		{
			return *clientConnection;
		}
	}
	throw NotFoundException("ClientConnection not found for the specified nickname.");
}

ClientConnection &IRCServer::getClientConnectionBySocket(int socket)
{
	for (std::vector<ClientConnection *>::const_iterator it = _clientConnections.begin(); it != _clientConnections.end(); ++it)
	{
		ClientConnection *clientConnection = *it;
		if (clientConnection->getSocketFileDescriptor() == socket)
		{
			return *clientConnection;
		}
	}
	throw NotFoundException("ClientConnection not found for the specified socket.");
}

const std::string &IRCServer::getPassword() const
{
	return _password;
}

void IRCServer::sendPingToAllClients()
{
	std::string pingMsg = "PING\r\n";
	for (std::vector<ClientConnection *>::iterator it = _clientConnections.begin(); it != _clientConnections.end(); ++it)
	{
		(*it)->sendMessage(pingMsg);
		// send((*it)->getSocketFileDescriptor(), pingMsg.c_str(), pingMsg.size(), 0);
	}
}
