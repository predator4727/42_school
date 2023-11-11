/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:50:57 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 21:22:52 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): AAnimal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->_dogBrain = new Brain();
	return;
}

Dog::Dog(const Dog &copy): AAnimal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = copy.type;
	this->_dogBrain = new Brain(*copy._dogBrain);
	return;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &copy) 
	{
		AAnimal::operator=(copy);
		this->type = copy.type;
        delete this->_dogBrain;
        this->_dogBrain = new Brain(*copy._dogBrain);
    }
	return (*this);
}

Dog::~Dog() { 
	delete this->_dogBrain; 
	std::cout << "Dog destructor called" << std::endl; 
}

void Dog::makeSound() const { std::cout << "Bark" << std::endl; }

Brain	*Dog::getBrain() const { return (this->_dogBrain); }