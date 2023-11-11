/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 04:59:06 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/18 09:35:53 by aderugo          ###   ########.fr       */
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
	Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);
	~Fixed();
	Fixed(const int value);
	Fixed(const float value);
	float	toFloat() const;
	int		toInt() const;
	int 	getRawBits(void) const;
	void	setRawBits(int const raw);
	void	setRawBits(float const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &copy);

#endif