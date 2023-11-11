/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:37:08 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/16 22:26:48 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

	private:
		std::string _name;

	public:
		Zombie(std::string name);
		~Zombie();
		void announce( void );
		// std::string getName() const;
		// void setName(std::string newName);

};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif //***********************ZOMBIE_HPP