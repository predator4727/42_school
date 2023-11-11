/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:50:43 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 17:55:25 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): type("Animal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
	return;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = copy;
	return;
}

AAnimal &AAnimal::operator=(const AAnimal &copy)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	this->type = copy.type;
	return (*this);
}

AAnimal::~AAnimal() { std::cout << "AAnimal destructor called" << std::endl; }

std::string AAnimal::getType() const { return this->type; }
