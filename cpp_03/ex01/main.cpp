/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 01:30:04 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 12:39:53 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	std::string input1;
    std::string input2;
    std::string input3;
    std::string input4;	
	std::cout << "Input name of clap: ";
	std::getline(std::cin >> std::ws, input1);
	std::cout << "Input name of clap's victim: ";
	std::getline(std::cin >> std::ws, input2);
    std::cout << "Input name of scav: ";
	std::getline(std::cin >> std::ws, input3);
	std::cout << "Input name of scav's victim: ";
	std::getline(std::cin >> std::ws, input4);
	
	if (!input1.empty() && !input2.empty() && !input3.empty() && !input4.empty())
	{
		ClapTrap clap(input1);
		clap.attack(input2);
		clap.takeDamage(1);
		clap.beRepaired(2);
		ScavTrap scav(input3);
		scav.attack(input4);
		scav.takeDamage(3);
		scav.beRepaired(4);
		scav.guardGate();
	}
	if (std::cin.eof() || std::cin.bad()) 
	{
		std::cerr << "EOF" << std::endl;
        return (1);
	}
	return 0;
}
