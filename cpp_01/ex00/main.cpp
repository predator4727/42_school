/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:32:21 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/12 19:53:57 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
    std::string name;

    std::cout << "Stack Zombie." << std::endl;
    std::cout << "Zombie name: ";
    std::getline(std::cin >> std::ws, name);
    Zombie zombi1(name);
    
    std::cout << "Heap Zombie" << std::endl;
    std::cout << "Zombie name: ";
    std::getline(std::cin >> std::ws, name);
    Zombie* zombi2 = newZombie(name);
    zombi2->announce();
    delete zombi2;

    std::cout << "RandomChump()" << std::endl;
    randomChump("random");
    return 0;
}