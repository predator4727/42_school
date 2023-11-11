/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientConnection.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:25:35 by oaydemir          #+#    #+#             */
/*   Updated: 2023/06/06 20:34:25 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_CONNECTION_HPP
# define CLIENT_CONNECTION_HPP

# include <string>
# include <memory>
# include "User/User.hpp"
# include "Channel/Channel.hpp"
# include "MessageToolkit/MessageToolkit.hpp"

class IRCServer;
class Command;

class ClientConnection
{
	private:
		IRCServer& _server;
		
		User& _user;
		char buffer[4096];
		ssize_t bytesRead;

		ClientConnection(const ClientConnection &src);
		ClientConnection &operator=(const ClientConnection &src);

	public:
		int _socketFileDescriptor;
		
		ClientConnection(IRCServer &server, int socketFileDescriptor, User& user);
		~ClientConnection();

		int getSocketFileDescriptor() const;
		
		User& getUser() const;
		IRCServer& getServer() const;
		
		void setUser(const User &user);

		bool isCompleteMessage(const std::string &message) const;

		void handleIncomingMessage();
		void sendMessage(std::string message) const;
		void closeConnection();

		Command *createCommand(const ParsedMessage& parsedMessage);
};

#endif
