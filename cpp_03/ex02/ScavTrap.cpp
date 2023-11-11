/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:56:48 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 12:55:53 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string* newName): ClapTrap(newName)
{
	std::cout << "Parametralized constructor ScavTrap called" << std::endl;
	if(newName == nullptr || (*newName).empty()) 
	{
		std::cerr << "Error: name" << std::endl;
		exit(1);
	}
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackPoints = 20;
	return;
}

ScavTrap::ScavTrap(std::string newName): ClapTrap(newName)
{
	std::cout << "Parametralized constructor ScavTrap called" << std::endl;
	if(newName.empty()) 
	{
		std::cerr << "Error: name" << std::endl;
		exit(1);
	}
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackPoints = 20;
	return;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	std::cout << "Copy constructor ScavTrap called" << std::endl;
	*this = copy;
	return;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "Copy assignment operator ScavTrap called" << std::endl;
	if (this != &copy) {
        ClapTrap::operator=(copy);
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackPoints = copy._attackPoints;
	}
	return (*this);
}

ScavTrap::~ScavTrap() { std::cout << "Destructor ScavTrap called" << std::endl; }

void ScavTrap::attack(const std::string& target) {
	if (target.empty()) 
	{
		std::cerr << "Error: name" << std::endl;
		exit(1);
	}
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", doing " << this->_attackPoints << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	} else {
		std::cout << "ScavTrap " << this->_name << " can't do anything yet" << std::endl;
		return;
	}
}

void ScavTrap::attack(const std::string* target) {
	if (target == nullptr || (*target).empty()) 
	{
		std::cerr << "Error: name" << std::endl;
		exit(1);
	}
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", doing " << this->_attackPoints << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	} else {
		std::cout << "ScavTrap " << this->_name << " can't do anything yet" << std::endl;
		return;
	}
}

void ScavTrap::guardGate() { std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl; }
