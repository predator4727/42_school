/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:34:38 by aderugo           #+#    #+#             */
/*   Updated: 2023/06/29 14:31:46 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include <exception>


class RPN {
	private:
		RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN();
	public:
		static double calculate(std::string expression);
};

#endif //**********************************************RPN_HPP