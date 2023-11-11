/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:35:34 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/16 22:27:09 by aderugo          ###   ########.fr       */
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
		Zombie();
		~Zombie();
		Zombie(std::string name);
		void announce( void );
		void setName(std::string newName);
};

Zombie* zombieHorde( int N, std::string name );

#endif //******************************ZOMBIE_HPP