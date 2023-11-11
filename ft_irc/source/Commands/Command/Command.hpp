/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:25:43 by oaydemir          #+#    #+#             */
/*   Updated: 2023/05/12 18:48:31 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

# include "ClientConnection/ClientConnection.hpp"
# include "MessageToolkit/MessageToolkit.hpp"
# include "IRCServer/IRCServer.hpp"

class Command
{
	protected:
		ClientConnection& _clientConnection;
		const ParsedMessage _parsedMessage;
	public:
		Command(ClientConnection& clientConnection, const ParsedMessage& parsedMessage);
		Command(const Command &source);
		virtual ~Command();

		virtual void execute() = 0;
};

#endif