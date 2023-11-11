/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NickCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:26:00 by oaydemir          #+#    #+#             */
/*   Updated: 2023/05/01 17:02:21 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NICKNAMECOMMAND_HPP
# define NICKNAMECOMMAND_HPP

# include "Commands/Command/Command.hpp"

class NickCommand : public Command
{
	public:
		NickCommand(ClientConnection& clientConnection, const ParsedMessage& parsedMessage);
		NickCommand(const NickCommand& source);
		virtual ~NickCommand();

		virtual void execute();
};

#endif