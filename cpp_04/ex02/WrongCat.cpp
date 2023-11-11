/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:51:52 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 18:01:22 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
	return;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
	return;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &copy) 
	{
		WrongAnimal::operator=(copy);
		this->type = copy.type;
	}
	return (*this);
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

void WrongCat::makeSound() const { std::cout << "Maya" << std::endl; }