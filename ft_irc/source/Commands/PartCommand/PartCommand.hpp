/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PartCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 07:40:55 by oaydemir          #+#    #+#             */
/*   Updated: 2023/05/01 17:02:21 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PART_COMMAND_HPP
# define PART_COMMAND_HPP

# include "Commands/Command/Command.hpp"

class PartCommand : public Command
{
public:
	PartCommand(ClientConnection& clientConnection, const ParsedMessage& parsedMessage);
	PartCommand(const PartCommand& source);
	virtual ~PartCommand();

	virtual void execute();
};

#endif
