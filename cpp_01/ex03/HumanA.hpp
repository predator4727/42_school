/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 02:01:48 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/16 22:27:31 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {
	
	private:

		std::string _name;
		Weapon& _weapon;
		
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void attack( void ) const;
};

#endif //*****************************HUMANA_HPP