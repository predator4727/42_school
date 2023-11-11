/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 01:52:32 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/15 20:53:54 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {}

Weapon::~Weapon() {}

const  std::string& Weapon::getType( void ) { return this->_type; }

void Weapon::setType(std::string newType) { this->_type = newType; }