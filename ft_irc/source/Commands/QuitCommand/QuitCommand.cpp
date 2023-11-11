/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuitCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:46:27 by oaydemir          #+#    #+#             */
/*   Updated: 2023/06/07 23:25:22 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "QuitCommand.hpp"
#include "ClientConnection/ClientConnection.hpp"
#include "User/User.hpp"

QuitCommand::QuitCommand(ClientConnection &clientConnection, const ParsedMessage &parsedMessage)
	: Command(clientConnection, parsedMessage)
{
}

QuitCommand::QuitCommand(const QuitCommand &source)
	: Command(source)
{
}

QuitCommand::~QuitCommand()
{
}

void QuitCommand::execute()
{
	std::string quitMessage = "";
	if (_parsedMessage.parameters.size() >= 1)
		quitMessage = _parsedMessage.parameters[0];
	// send confirmation to client
	_clientConnection.sendMessage(_clientConnection.getUser().getNickname() + " user left. Message"
																			  " (" +
								  quitMessage + ")");
	std::cout << "quit\n";
	_clientConnection.getServer().removeUser(_clientConnection.getUser());
	_clientConnection.getServer().removeClientConnection(_clientConnection);
	int targetFd = _clientConnection._socketFileDescriptor;
	_clientConnection.closeConnection();
	for (std::vector<pollfd>::iterator it = _clientConnection.getServer().pollFds.begin(); it != _clientConnection.getServer().pollFds.end(); ++it)
	{
		if (it->fd == targetFd)
		{
			_clientConnection.getServer().pollFds.erase(it);
			break; // Assuming you only want to remove the first matching fd.
		}
	}
	delete &(_clientConnection.getUser());
	delete &_clientConnection;
}
