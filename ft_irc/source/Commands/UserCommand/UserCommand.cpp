/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:26:15 by oaydemir          #+#    #+#             */
/*   Updated: 2023/05/12 18:53:58 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "UserCommand.hpp"
#include "ClientConnection/ClientConnection.hpp"
#include "User/User.hpp"


UserCommand::UserCommand(ClientConnection& clientConnection, const ParsedMessage& parsedMessage)
    : Command(clientConnection, parsedMessage)
{
}

UserCommand::UserCommand(const UserCommand& source)
    : Command(source)
{
}

UserCommand::~UserCommand()
{
}

void UserCommand::execute()
{
    User& user = _clientConnection.getUser();
	if (!user.isAuthorized())
	{
		_clientConnection.sendMessage("451 :You are not authorized");
		return;
	}
    if (_parsedMessage.parameters.size() != 4)
    {
		_clientConnection.sendMessage("461 :Syntax error: Not enough parameters for USER command");
		return;
    }
    user.setUsername(_parsedMessage.parameters[0]);
	std::cout << "Username changed to " << user.getUsername() << std::endl;
}
