/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuitCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:45:58 by oaydemir          #+#    #+#             */
/*   Updated: 2023/05/01 17:02:21 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUIT_COMMAND_HPP
#define QUIT_COMMAND_HPP

#include "Commands/Command/Command.hpp"

class QuitCommand : public Command
{
public:
	QuitCommand(ClientConnection& clientConnection, const ParsedMessage& parsedMessage);
	QuitCommand(const QuitCommand& source);
	virtual ~QuitCommand();

	virtual void execute();
};

#endif