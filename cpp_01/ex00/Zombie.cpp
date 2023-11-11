/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:52:36 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/14 14:20:17 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie(std::string name): _name(name)
{}

//void Zombie::setName(std::string name) { this->_name = name; }

//std::string Zombie::getName() const { return this->_name; }


// Zombie::~Zombie() {std::cout << "Zombie " << Zombie::getName() << " was destroyed" << std::endl;}

// void Zombie::announce( void ) { std::cout << Zombie::getName() << ": BraiiiiiiinnnzzzZ..." << std::endl; }

Zombie::~Zombie() {std::cout << "Zombie " << this->_name << " was destroyed" << std::endl;}

void Zombie::announce( void ) { std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl; }
