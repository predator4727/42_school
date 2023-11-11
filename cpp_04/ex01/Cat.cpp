/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:50:50 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 20:47:23 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->_catBrain = new Brain();
	return;
}

Cat::Cat(const Cat &copy): Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = copy.type;
	this->_catBrain = new Brain(*copy._catBrain);
	return;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &copy) 
	{
		Animal::operator=(copy);
		this->type = copy.type;
		delete this->_catBrain;
        this->_catBrain = new Brain(*copy._catBrain);
    }
	return (*this);
}

Cat::~Cat() 
{ 
	delete this->_catBrain; 
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const { std::cout << "Maya" << std::endl; }

Brain	*Cat::getBrain() const { return (this->_catBrain); }



