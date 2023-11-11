/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:26:17 by oaydemir          #+#    #+#             */
/*   Updated: 2023/05/01 17:02:21 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_COMMAND_HPP
#define USER_COMMAND_HPP

#include "Commands/Command/Command.hpp"

class UserCommand : public Command
{
public:
	UserCommand(ClientConnection& clientConnection, const ParsedMessage& parsedMessage);
	UserCommand(const UserCommand& source);
	virtual ~UserCommand();

	virtual void execute();
};

#endif
