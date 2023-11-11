/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 05:40:19 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/05 23:40:27 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <string>
# include <climits>
# include <cmath>
# include <cstdlib>

class ScalarConverter
{
	private:
		static std::string str;

		static char		toChar( void );
		static int		toInteger( void );
		static float	toFloat (void);
		static double	toDouble (void );

		static void		printAll( void );

		ScalarConverter();
		ScalarConverter( ScalarConverter const & copy );
		ScalarConverter &operator=( ScalarConverter const & copy );
		~ScalarConverter();

	public:
		static void	convert( std::string const &str );
};

#endif //******************************************SCALAR_CONVERTER_HPP