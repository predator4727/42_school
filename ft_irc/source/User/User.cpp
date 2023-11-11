/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 02:04:22 by oaydemir          #+#    #+#             */
/*   Updated: 2023/05/01 07:28:27 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

User::User() : _nickname(""), _username(""), _isAuthorized(false)
{
}

User::~User()
{
}

User::User(const User &src)
{
	*this = src;
}

User &User::operator=(const User &src)
{
	if (this != &src)
	{
		_nickname = src._nickname;
		_username = src._username;
	}
	return *this;
}

std::string User::getNickname() const
{
	return _nickname;
}

std::string User::getUsername() const
{
	return _username;
}

bool User::isAuthorized() const
{
	return _isAuthorized;
}

void User::setNickname(const std::string& nickname)
{
	_nickname = nickname;
}

void User::setUsername(const std::string& username)
{
	_username = username;
}

void User::setAuthorized(bool isAuthorized)
{
	_isAuthorized = isAuthorized;
}
