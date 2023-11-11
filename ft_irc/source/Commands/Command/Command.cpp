/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:25:41 by oaydemir          #+#    #+#             */
/*   Updated: 2023/05/01 17:01:07 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Command::Command(ClientConnection& clientConnection, const ParsedMessage& parsedMessage)
	: _clientConnection(clientConnection), _parsedMessage(parsedMessage)
{
}

Command::~Command()
{
}

Command::Command(const Command &source) : _clientConnection(source._clientConnection), _parsedMessage(source._parsedMessage)
{
}
