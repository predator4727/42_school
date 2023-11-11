/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:50:43 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 22:36:40 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
	return;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
	return;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	this->type = copy.type;
	return (*this);
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

std::string Animal::getType() const { return this->type; }

void Animal::makeSound() const { std::cout << "ANIMAL" << std::endl; }

void Animal::setType(std::string type) { this->type = type; }