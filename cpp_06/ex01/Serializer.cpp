/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:39:11 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/01 22:51:42 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() { std::cout << "Constructor called" << std::endl; }

Serializer::Serializer( const Serializer & copy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return;
}

Serializer &Serializer::operator=( Serializer const & copy ) 
{
	std::cout << "Serializer copy assignment operator called" << std::endl;
	if ( this != &copy )
		return *this; 
	return *this; 
}

Serializer::~Serializer() { std::cout << "Destructor called" << std::endl; }

uintptr_t Serializer::serialize(Data* ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data* Serializer::deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }