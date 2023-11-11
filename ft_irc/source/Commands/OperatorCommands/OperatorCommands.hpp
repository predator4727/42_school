/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperatorCommands.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 07:57:14 by oaydemir          #+#    #+#             */
/*   Updated: 2023/05/01 17:02:21 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_COMMAND_HPP
#define OPERATOR_COMMAND_HPP

#include "Commands/Command/Command.hpp"

class OperatorCommands : public Command
{
public:
	OperatorCommands(ClientConnection& clientConnection, const ParsedMessage& parsedMessage);
	OperatorCommands(const OperatorCommands& source);
	virtual ~OperatorCommands();

	virtual void execute();

private:
	void _mode();
	void _topic();
	void _invite();
	void _kick();
};

#endif