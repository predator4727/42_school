/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:50:57 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 17:45:10 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	return;
}

Dog::Dog(const Dog &copy): Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
	return;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &copy) 
	{
        Animal::operator=(copy);
		this->type = copy.type;
	}
	return (*this);
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

void Dog::makeSound() const { std::cout << "Bark" << std::endl; }