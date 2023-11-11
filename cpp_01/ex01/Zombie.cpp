/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:35:31 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/14 22:33:23 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name): _name(name) {}

void Zombie::setName(std::string name) { this->_name = name; }

Zombie::~Zombie() {std::cout << "Zombie " << this->_name << " was destroyed" << std::endl;}

void Zombie::announce( void ) { std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl; }