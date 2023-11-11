/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NickCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:25:58 by oaydemir          #+#    #+#             */
/*   Updated: 2023/05/12 18:50:41 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NickCommand.hpp"
#include <iostream>

NickCommand::NickCommand(ClientConnection& clientConnection, const ParsedMessage &parsedMessage)
    : Command(clientConnection, parsedMessage)
{
}

NickCommand::~NickCommand()
{
}

NickCommand::NickCommand(const NickCommand &source)
    : Command(source)
{
}

void NickCommand::execute()
{
	// Check if the user is authorized
	if (!_clientConnection.getUser().isAuthorized())
	{
		// Send the ERR_NOTREGISTERED message
		_clientConnection.sendMessage("451 :You have not registered");
		return;
	}
    if (_parsedMessage.parameters.size() != 1)
    {
        // Send the ERR_NEEDMOREPARAMS message
		_clientConnection.sendMessage("461 " + _parsedMessage.command + " :Not enough parameters");
        return;
    }

    std::string newNickname = _parsedMessage.parameters[0];

    // Check if the new nickname is valid and not taken by another user
    if (!(_clientConnection.getServer().isNicknameAvailable(newNickname)))
    {
        // Send an error message for an already taken or invalid nickname
        _clientConnection.sendMessage("433 " + newNickname + " :Nickname is already in use");
        return;
    }

    // If the nickname is valid and available, set it
    _clientConnection.getUser().setNickname(newNickname);
	std::cout << "Nickname changed to " << _clientConnection.getUser().getNickname() << std::endl;

    // Send a confirmation message or perform other actions as needed
	_clientConnection.sendMessage("NICK :" + newNickname);
}
