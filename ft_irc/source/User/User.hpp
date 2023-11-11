/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:53:45 by oaydemir          #+#    #+#             */
/*   Updated: 2023/05/12 18:46:03 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
# define USER_HPP

# include <string>

class User
{
	private:
		std::string _nickname;
		std::string _username;
		bool		_isAuthorized;

	public:
		User();
		~User();
		User(const User &src);
		User &operator=(const User &src);

		std::string getNickname() const;
		std::string getUsername() const;
		bool		isAuthorized() const;
		
		void		setNickname(const std::string& nickname);
		void		setUsername(const std::string& username);
		void		setAuthorized(bool isAuthorized);
};

#endif