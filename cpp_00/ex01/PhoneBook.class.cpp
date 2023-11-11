/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:22:01 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/12 17:51:21 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	 std::cout << "Constructor released" << std::endl;
	 return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor released" << std::endl;
	return;
}

void    PhoneBook::intro(void) const {
    std::cout << "------PHONEBOOK INFO-------" << std::endl;
    std::cout << "ADD\t: add contact" << std::endl;
    std::cout << "SEARCH\t: search contact" << std::endl;
    std::cout << "EXIT\t: exit" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << std::endl;
}

void    PhoneBook::add(void) {
    static int  i;
    this->_contacts[i % 8].createContact(i % 8);
    i++;
}

void    PhoneBook::search(void) const {
	std::cout << "------------- PHONEBOOK CONTACTS -------------" << std::endl;
    for (size_t i = 0; i < 8; i++) {
        this->_contacts[i].showTable(i);
    }
    std::cout << std::endl;
	std::string input = "-1";
    while (1)
	{
		std::cout << "Please enter the contact index: ";
        input.clear();
        std::getline(std::cin >> std::ws, input);
        if (input.length() == 1 && !std::isalpha(input.at(0))) {
            if (std::cin.good() && std::atoi(input.c_str()) >= 0 && std::atoi(input.c_str()) < 8) {
                break;
            }
        } 
        if (std::cin.eof() || std::cin.bad()) {
            std::cerr << "EOF" << std::endl;
            exit(1);
        }
        std::cout << "Invalid index! You can check just 0-7 indexes " << std::endl;
	}
    this->_contacts[std::atoi(input.c_str())].find(std::atoi(input.c_str()));
}
