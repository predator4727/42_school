/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:30:49 by oaydemir          #+#    #+#             */
/*   Updated: 2023/05/01 17:02:21 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PassCommand.hpp"
#include "ClientConnection/ClientConnection.hpp"
#include "IRCServer/IRCServer.hpp"


PassCommand::PassCommand(ClientConnection& clientConnection, const ParsedMessage& parsedMessage)
    : Command(clientConnection, parsedMessage)
{
}

PassCommand::PassCommand(const PassCommand& source)
    : Command(source)
{
}

PassCommand::~PassCommand()
{
}

void PassCommand::execute()
{
	if (_parsedMessage.parameters.size() != 1)
	{
		_clientConnection.sendMessage("461 " + _parsedMessage.command + " :Not enough parameters");
	}
	const std::string& password = _clientConnection.getServer().getPassword();
	if (_parsedMessage.parameters[0] != password)
	{
		_clientConnection.sendMessage("464 " + _parsedMessage.command + " :Password incorrect");
		return;
	}
	_clientConnection.getUser().setAuthorized(true);
}
