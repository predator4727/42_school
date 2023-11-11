/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 03:05:53 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/16 02:47:58 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
	std::string input;
	std::cout << "Input DEBUG, INFO, WARNING or ERROR" << std::endl;
	std::cout << "For exit use EXIT" << std::endl;
	std::cout << std::endl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Harl harl;
	while(1)
	{
		std::getline(std::cin >> std::ws, input);
		for(int i=0; i < 4; i++) {
			if(!levels[i].compare(input)) {
				harl.complain(input);
				std::cout << std::endl;
			} else if(!input.compare("EXIT")) {
				return 0;
			}
		}	
	}
}
