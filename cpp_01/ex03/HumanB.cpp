/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 02:01:40 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/15 02:43:45 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name) { this->_weapon = NULL; }

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) { this->_weapon = &weapon; }

void HumanB::attack( void ) const {
	if(this->_weapon->getType() != "" && this->_weapon != NULL)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " doesn't have a weapon " << std::endl;
}