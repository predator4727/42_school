/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:35:27 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/16 21:58:02 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	std::string name;
	std::string N;
	std::cout << "Zombie name: ";
    std::getline(std::cin >> std::ws, name);
	std::cout << "Number of zombies: ";
    std::getline(std::cin >> std::ws, N);
	if (!std::isdigit(std::atoi(N.c_str())))
	{
		Zombie* zombieHords = zombieHorde(std::atoi(N.c_str()), name);
		delete [] zombieHords;
		return 0;
	}
}