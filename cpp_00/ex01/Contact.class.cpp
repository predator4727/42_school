/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:17:28 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/12 17:50:21 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <iostream>

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string Contact::fillContact(std::string str) const {
    std::string input;
    while(1)
    {  
        std::cout << str;
        input.clear();
        std::getline(std::cin >> std::ws, input);
        if (std::cin.good() && !input.empty())
            break;
        if (std::cin.eof() || std::cin.bad()) {
            std::cerr << "EOF" << std::endl;
            exit(1);
        }
    }
    return (input);
}

void    Contact::createContact(int i) {
    this->_firstName = this->fillContact("Please enter you first name: ");
    this->_lastName = this->fillContact("Please enter your last name: ");
    this->_nickname = this->fillContact("Please enter your nickname: ");
    this->_nickname = this->fillContact("Please enter your phone number: ");
    this->_nickname = this->fillContact("Please enter your darkest secret: ");
	this->_index = i;
    std::cout << std::endl;
}

std::string Contact::display(std::string str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    Contact::showTable(int index) const {
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return ;
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << this->display(this->_firstName);
    std::cout << "|" << std::setw(10) << this->display(this->_lastName);
    std::cout << "|" << std::setw(10) << this->display(this->_nickname);
    std::cout << "|" << std::endl;
}

void    Contact::find(int index) const {
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return ;
    std::cout << std::endl;
    std::cout << "CONTACT index: \t" << index <<std::endl;
    std::cout << "First Name:\t" << this->_firstName << std::endl;
    std::cout << "Last Name:\t" << this->_lastName << std::endl;
    std::cout << "Nickname:\t" << this->_nickname << std::endl;
    std::cout << std::endl;
}