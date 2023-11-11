/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 04:58:44 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/19 01:08:44 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(value);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(value);
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = copy.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &copy)
{
	out << copy.toFloat();
	return (out);
}

int	Fixed::getRawBits(void) const { return (this->_value); }

void	Fixed::setRawBits(int const raw) { this->_value = raw << this->_fractionalBits; }

void	Fixed::setRawBits(float const raw) { this->_value = roundf(raw * (1 << this->_fractionalBits)); }

float	Fixed::toFloat() const { return ((float)this->_value / (float)(1 << this->_fractionalBits)); }

int	Fixed::toInt() const { return (this->_value >> this->_fractionalBits); }

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

