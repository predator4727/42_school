/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 05:40:24 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/05 22:52:39 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "MyException.hpp"


std::string ScalarConverter::str;

ScalarConverter::ScalarConverter() { std::cout << "Constructor called" << std::endl; }

ScalarConverter::ScalarConverter( const ScalarConverter & copy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return;
}

ScalarConverter &ScalarConverter::operator=( ScalarConverter const & copy )
{
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	if ( this != &copy )
		this->str = copy.str;
	return *this;
}

ScalarConverter::~ScalarConverter() { std::cout << "Destructor called" << std::endl; }


const char* ConversionException::what() const throw() { return "Conversion is impossible! Input char, integer, float or double"; }


char	ScalarConverter::toChar( void ) { return (static_cast<char>(ScalarConverter::toDouble())); }

int		ScalarConverter::toInteger( void ) { return (static_cast<int>(ScalarConverter::toDouble())); }

float	ScalarConverter::toFloat (void) { return (static_cast<float>(ScalarConverter::toDouble())); }

double	ScalarConverter::toDouble (void )
{
	if(ScalarConverter::str.size() == 1 && !isdigit(ScalarConverter::str[0]))
		return static_cast<double>(ScalarConverter::str[0]);
	else
		return static_cast<double>(std::atof(ScalarConverter::str.c_str()));
}


void	ScalarConverter::printAll( void )
{
	std::cout << "char: ";
	if (!std::isprint(ScalarConverter::toChar()) && isascii(ScalarConverter::toDouble()) && !std::isinf(ScalarConverter::toDouble()) && !std::isnan(ScalarConverter::toDouble()))
		std::cout << "Non displayable" << std::endl;
	else if (std::isprint(ScalarConverter::toChar()) && (ScalarConverter::toInteger() <= 127) && (ScalarConverter::toInteger() > 0))
		std::cout << "'" <<  ScalarConverter::toChar() << "'" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "int: ";
	if (ScalarConverter::toDouble() > INT_MAX || ScalarConverter::toDouble() < INT_MIN || std::isnan(ScalarConverter::toDouble()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << ScalarConverter::toInteger() << std::endl;

	std::cout << "float: " << ScalarConverter::toFloat();
	if ((ScalarConverter::toFloat() - ScalarConverter::toInteger()) == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << ScalarConverter::toDouble();
	if ((ScalarConverter::toDouble() - ScalarConverter::toInteger()) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::convert( std::string const &str )
{
	char	*endptr;
	double	temp;

	ScalarConverter::str = str;
	temp = std::strtod(ScalarConverter::str.c_str(), &endptr);
	if (ScalarConverter::str.length() < 2)
	{
		if (!(ScalarConverter::str[0]) || !isascii(ScalarConverter::str[0]))
			throw ConversionException();
	}
	else
	{
		if ((*endptr == 'f' && *(endptr + 1) != 0) || (*endptr != 0 && *endptr != 'f'))
			throw ConversionException();
	}
	(void)temp;
	ScalarConverter::printAll();
}
