/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 04:14:49 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/14 17:38:19 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	decrement(int &n) { n--; }

template <typename T>
void print( T const &str ) { std::cout << str << std::endl; return; }

int main( void ) 
{
	int	num[3] = {1, 2, 3};
	for (size_t i = 0; i < 3; i++)
		std::cout << num[i] << " ";
	std::cout << std::endl;
	iter(num, 3, decrement);
	for (size_t i = 0; i < 3; i++)
		std::cout << num[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;
	std::string str[3] = { "white", "blue", "yellow" };
	iter(str, 3, print);
	return 0;
}

// class Awesome {
//     public:
//         Awesome( void ) : _n( 42 ) { return; }
//         int get( void ) const { return this->_n; }
//     private:
//         int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

// template< typename T >
// void print( T const &x ) { std::cout << x << std::endl; return; }

// int main()
// {
//     int tab[] = { 0, 1, 2, 3, 4 };
//     Awesome tab2[5];

//     iter(tab, 5, print);
//     iter(tab2, 5, print);
//     return 0;
// }
