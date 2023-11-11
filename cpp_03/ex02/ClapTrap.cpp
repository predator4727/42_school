/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 01:29:57 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 12:59:55 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string* newName): _hitPoints(10), _energyPoints(10), _attackPoints(0)
{
	std::cout << "Parametralized constructor ClapTrap called" << std::endl;
	if(newName == nullptr || (*newName).empty()) {
		std::cerr << "Error: name" << std::endl;
		exit(1);
	} else {
		this->_name = *newName;
	}
	return;
}

ClapTrap::ClapTrap(std::string newName): _hitPoints(10), _energyPoints(10), _attackPoints(0)
{
	std::cout << "Parametralized constructor ClapTrap called" << std::endl;
	if(newName.empty()) {
		std::cerr << "Error: name" << std::endl;
		exit(1);
	} else {
		this->_name = newName;
	}
	return;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor ClapTrap called" << std::endl;
	*this = copy;
	return;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Copy assignment operator ClapTrap called" << std::endl;
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackPoints = copy._attackPoints;
	return (*this);
}

ClapTrap::~ClapTrap() { std::cout << "Destructor ClapTrap called" << std::endl; }

void ClapTrap::attack(const std::string& target) {
	if(target.empty()) {
		std::cerr << "Error: name" << std::endl;
		exit(1);
	}
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackPoints << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	} else {
		std::cout << "ClapTrap " << this->_name << " can't do anything" << std::endl;
		return;
	}
}

void ClapTrap::attack(const std::string* target) {
	if(target == nullptr || (*target).empty()) {
		std::cerr << "Error: name" << std::endl;
		exit(1);
	}
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackPoints << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	} else {
		std::cout << " ClapTrap " << this->_name << " can't do anything" << std::endl;
		return;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->_hitPoints > amount) {
		std::cout << "ClapTrap " << this->_name << " gets " << amount << " damage" << std::endl;
		this->_hitPoints -= amount;
	} else {
		std::cout << " ClapTrap " << this->_name << " seems like dead" << std::endl;
		return;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->_energyPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " gets " << amount << " hit points" << std::endl;
		this->_energyPoints -= 1;
		this->_hitPoints += amount;
	} else {
		std::cout << " ClapTrap " << this->_name << " can't do anything" << std::endl;
		return;
	}
}
