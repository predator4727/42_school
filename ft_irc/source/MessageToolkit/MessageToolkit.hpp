/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MessageToolkit.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:26:31 by oaydemir          #+#    #+#             */
/*   Updated: 2023/06/04 17:02:01 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
# define MESSAGE_HPP

# include <string>
# include <vector>

struct ParsedMessage
{
    std::string command;
    std::vector<std::string> parameters;
    std::string prefix;
};

class MessageToolkit
{
	private:
		std::string trimMessageTerminators(const std::string &message);
		std::vector<std::string> tokenizeString(const std::string &input);

	public:
		MessageToolkit();
		~MessageToolkit();
		MessageToolkit(const MessageToolkit &source);
		MessageToolkit &operator=(const MessageToolkit &source);


		ParsedMessage parseIncomingMessage(const std::string& message);
		std::string generateOutgoingMessage(const ParsedMessage& message);
};

#endif