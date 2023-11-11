/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MessageToolkit.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:26:29 by oaydemir          #+#    #+#             */
/*   Updated: 2023/06/06 05:59:30 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MessageToolkit.hpp"
#include <stddef.h> // For std::size_t
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

MessageToolkit::MessageToolkit()
{
}

MessageToolkit::~MessageToolkit()
{
}

MessageToolkit::MessageToolkit(const MessageToolkit &source)
{
	*this = source;
}

MessageToolkit &MessageToolkit::operator=(const MessageToolkit &source)
{
	if(this != &source)
		return *this;
	return *this;
}

ParsedMessage MessageToolkit::parseIncomingMessage(const std::string &message)
{
	ParsedMessage parsedMessage;
	std::vector<std::string> tokens = tokenizeString(trimMessageTerminators(message));
	if (tokens.empty())
	{
		parsedMessage.command = "\r\n";
		return parsedMessage;
	}

	if (tokens[0].at(0) == ':')
	{
		// Extract the prefix
		parsedMessage.prefix = tokens[0].substr(1);
		tokens.erase(tokens.begin());
	}

	if (!tokens.empty())
	{
		parsedMessage.command = tokens[0];
		tokens.erase(tokens.begin());

		for (std::vector<std::string>::const_iterator it = tokens.begin(); it != tokens.end(); ++it)
		{
			parsedMessage.parameters.push_back(*it);
		}
	}
	return parsedMessage;
}

std::string MessageToolkit::generateOutgoingMessage(const ParsedMessage &message)
{
	std::string generatedMessage;

	if (!message.prefix.empty())
	{
		generatedMessage += ":" + message.prefix + " ";
	}

	generatedMessage += message.command;

	for (std::vector<std::string>::const_iterator it = message.parameters.begin(); it != message.parameters.end(); ++it)
	{
		generatedMessage += " " + *it;
	}

	generatedMessage += "\r\n";

	return generatedMessage;
}

std::string MessageToolkit::trimMessageTerminators(const std::string &message)
{
	if (message.length() >= 2 && message.substr(message.length() - 2) == "\r\n")
	{
		return message.substr(0, message.length() - 2);
	}
	else
	{
		throw std::runtime_error("Message does not end with CRLF");
	}
}

std::vector<std::string> MessageToolkit::tokenizeString(const std::string &input)
{
	std::vector<std::string> result;
	std::string token;
	std::istringstream iss(input);

	while (std::getline(iss, token, ' '))
	{
		std::size_t colonPos = token.find(':');
		if (colonPos != std::string::npos)
		{
			std::string restOfLine = token.substr(colonPos + 1);
			if (iss.tellg() != std::istringstream::pos_type(-1))
			{
				restOfLine += ' ' + iss.str().substr(iss.tellg());
			}
			result.push_back(restOfLine);
			break;
		}
		else
		{
			result.push_back(token);
		}
	}

	return result;
}
