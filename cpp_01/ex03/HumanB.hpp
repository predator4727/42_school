/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 02:01:59 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/16 22:27:40 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
	
	private:

		std::string _name;
		Weapon* _weapon;

	public:
		HumanB(std::string name);
		~HumanB();
		void setWeapon(Weapon& weapon);
		void attack( void ) const;
};

#endif //*****************************HUMANB_HPP