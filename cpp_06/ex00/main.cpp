/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 05:40:28 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/05 23:39:45 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try {
			ScalarConverter::convert(argv[1]);
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	} else {
		std::cout << "ERROR: wrong input" << std::endl;
	}
	return (0);
}