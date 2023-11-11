/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 04:59:43 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/19 01:42:50 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;

	public:
		//Constructors and Destructor
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int Value);
		Fixed(const float Value);
		~Fixed();
		//overload
		Fixed &operator=(const Fixed &copy);
		//get and set
		int 	getRawBits(void) const;
		void	setRawBits(int const raw);
		void	setRawBits(float const raw);
		//convert
		float	toFloat() const;
		int		toInt() const;
		//overload arithmetics
		Fixed operator+(const Fixed &copy) const;
		Fixed operator-(const Fixed &copy) const;
		Fixed operator*(const Fixed &copy) const;
		Fixed operator/(const Fixed &copy) const;
		//overload comparison
		bool	operator>(const Fixed &copy) const;
		bool	operator<(const Fixed &copy) const;
		bool	operator==(const Fixed &copy) const;
		bool	operator!=(const Fixed &copy) const;
		bool	operator<=(const Fixed &copy) const;
		bool	operator>=(const Fixed &copy) const;
		//increment and decrement
		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed	operator++();
		Fixed	operator--();
		//static members
		static Fixed min(Fixed &a, Fixed &b);
		static Fixed max(Fixed &a, Fixed &b);
		static Fixed min(const Fixed &a, const Fixed &b);
		static Fixed max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &copy);

#endif