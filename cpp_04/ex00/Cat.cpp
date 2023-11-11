/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:50:50 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 17:02:49 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	return;
}

Cat::Cat(const Cat &copy): Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
	return;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if(this != &copy)
	{
		Animal::operator=(copy);
		this->type = copy.type;
	}
	return (*this);
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

void Cat::makeSound() const { std::cout << "Maya" << std::endl; }