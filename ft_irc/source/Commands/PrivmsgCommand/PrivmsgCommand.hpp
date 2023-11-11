/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrivmsgCommand.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 06:33:41 by oaydemir          #+#    #+#             */
/*   Updated: 2023/05/01 17:02:21 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVMSG_COMMAND_HPP
# define PRIVMSG_COMMAND_HPP

# include "Commands/Command/Command.hpp"

class PrivmsgCommand : public Command
{
public:
	PrivmsgCommand(ClientConnection& clientConnection, const ParsedMessage& parsedMessage);
	PrivmsgCommand(const PrivmsgCommand& source);
	virtual ~PrivmsgCommand();

	virtual void execute();

private:
	void sendToChannel(const std::string& channelName);
	void sendToUser(const std::string& username);
};

#endif