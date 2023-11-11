/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IRCServer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:26:22 by oaydemir          #+#    #+#             */
/*   Updated: 2023/06/06 01:44:14 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRC_SERVER_HPP
#define IRC_SERVER_HPP

#include <vector>
#include <string>
#include <stdexcept>
#include "ClientConnection/ClientConnection.hpp"
#include "User/User.hpp"
#include "Channel/Channel.hpp"
#include <algorithm>
#include <cstring>
#include <poll.h>

class NotFoundException : public std::runtime_error {
public:
    explicit NotFoundException(const std::string& message) : std::runtime_error(message) {}
};

class IRCServer {
private:
    int _socketFileDescriptor;
    std::string _password;
    std::vector<ClientConnection*> _clientConnections;
    std::vector<User*> _users;
    std::vector<Channel*> _channels;
	

public:
	std::vector<pollfd> pollFds;
    IRCServer(int port, const std::string& password);
    virtual ~IRCServer();


    // Main loop to accept new client connections and handle existing ones
    void run();

    // Adds and removes client connections
    void addClientConnection(ClientConnection& clientConnection);
    void removeClientConnection(ClientConnection& clientConnection);

    // Adds and removes users
    void addUser(User& user);
    void removeUser(User& user);

    // Adds and removes channels
	void addChannel(Channel* channel);
	void removeChannel(Channel *channel);

	// Checks if a nickname is available
	bool isNicknameAvailable(const std::string& nickname) const;

    // Getters
    ClientConnection& getClientConnectionByUser(const User& user);
    User& getUserByClientConnection(const ClientConnection& clientConnection);
    Channel& getChannelByName(const std::string& channelName);
	Channel& getChannelByName(const std::string& channelName) const;
	
	User& getUserByNickname(const std::string& nickname);
	User& getUserByNickname(const std::string& nickname) const;
	
	ClientConnection& getClientConnectionByNickname(const std::string& nickname);
	ClientConnection& getClientConnectionByNickname(const std::string& nickname) const;
	
	ClientConnection& getClientConnectionBySocket(int socket);
	const std::string& getPassword() const;

	void sendPingToAllClients();
};

#endif
