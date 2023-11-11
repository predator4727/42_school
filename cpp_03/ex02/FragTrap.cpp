/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 05:14:18 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 12:59:16 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string* newName): ClapTrap(newName)
{
	std::cout << "Parametralized constructor FragTrap called" << std::endl;
	if(newName == nullptr || (*newName).empty()) 
	{
		std::cerr << "Error: name" << std::endl;
		exit(1);
	}
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackPoints = 30;
	return;
}

FragTrap::FragTrap(std::string newName): ClapTrap(newName)
{
	std::cout << "Parametralized constructor FragTrap called" << std::endl;
	if(newName.empty()) 
	{
		std::cerr << "Error: name" << std::endl;
		exit(1);
	}
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackPoints = 30;
	return;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "Copy constructor FragTrap called" << std::endl;
	*this = copy;
	return;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "Copy assignment operator FragTrap called" << std::endl;
	if (this != &copy) {
        ClapTrap::operator=(copy);
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackPoints = copy._attackPoints;
	}
	return (*this);
}

FragTrap::~FragTrap() { std::cout << "Destructor FragTrap called" << std::endl; }

void FragTrap::highFivesGuys() { std::cout << "FragTrap " << this->_name << " send positive high fives" << std::endl; }
