/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JoinCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:00:57 by oaydemir          #+#    #+#             */
/*   Updated: 2023/05/01 17:02:21 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOIN_COMMAND_HPP
# define JOIN_COMMAND_HPP

# include "Commands/Command/Command.hpp"

class JoinCommand : public Command
{
public:
	JoinCommand(ClientConnection& clientConnection, const ParsedMessage& parsedMessage);
	JoinCommand(const JoinCommand& source);
	virtual ~JoinCommand();

	virtual void execute();
};

#endif
