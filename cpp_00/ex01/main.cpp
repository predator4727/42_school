/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:17:51 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/12 17:43:03 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>

int main(void) {
	PhoneBook book;
	std::string input;
	book.intro();
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin >> std::ws, input);
		if(!input.compare("ADD"))
			book.add();
		else if(!input.compare("SEARCH"))
			book.search();
		else if(!input.compare("EXIT"))
			break;
		else if (std::cin.eof() || std::cin.bad()) 
		{
            std::cerr << "EOF" << std::endl;
            exit(1);
        }
		else
		{
			std::cout << "Invalid command! " << std::endl;
			std::cin.clear();
			book.intro();
		}
	}
	return 0;
}
