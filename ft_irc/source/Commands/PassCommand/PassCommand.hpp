/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:30:47 by oaydemir          #+#    #+#             */
/*   Updated: 2023/05/01 17:02:21 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASS_COMMAND_HPP
#define PASS_COMMAND_HPP

#include "Commands/Command/Command.hpp"

class PassCommand : public Command
{
public:
	PassCommand(ClientConnection& clientConnection, const ParsedMessage& parsedMessage);
	PassCommand(const PassCommand& source);
	virtual ~PassCommand();

	virtual void execute();
};

#endif
