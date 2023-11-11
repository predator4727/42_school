/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 01:47:12 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/16 22:26:40 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {

	private:
		std::string _type;
		
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string& getType( void );
		void setType(std::string newType);
};

#endif //***************************WEAPON_HPP