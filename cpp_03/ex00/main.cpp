/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 01:30:04 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 12:43:55 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
    std::string input1;
    std::string input2;
	std::cout << "Input name of clap: ";
	std::getline(std::cin >> std::ws, input1);
	std::cout << "Input name of victim: ";
	std::getline(std::cin >> std::ws, input2);
	
	if (!input1.empty() && !input2.empty())
	{
		ClapTrap clap(input1);
		clap.attack(input2);
		clap.takeDamage(5);
	}
	if (std::cin.eof() || std::cin.bad()) 
	{
		std::cerr << "EOF" << std::endl;
        return(1);
	}
	return(0);
}