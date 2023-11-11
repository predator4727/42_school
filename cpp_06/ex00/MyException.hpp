/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyException.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:17:23 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/05 23:39:58 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYEXCEPTION_HPP
# define MYEXCEPTION_HPP

#include <exception>

class ConversionException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif //**************************MYEXCEPTION_HPP