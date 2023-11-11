/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NoticeCommand.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 06:33:41 by oaydemir          #+#    #+#             */
/*   Updated: 2023/05/12 04:24:50 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOTICE_COMMAND_HPP
# define NOTICE_COMMAND_HPP

# include "Commands/Command/Command.hpp"

class NoticeCommand : public Command
{
public:
	NoticeCommand(ClientConnection& clientConnection, const ParsedMessage& parsedMessage);
	NoticeCommand(const NoticeCommand& source);
	virtual ~NoticeCommand();

	virtual void execute();

private:
	void sendToChannel(const std::string& channelName);
	void sendToUser(const std::string& username);
};

#endif