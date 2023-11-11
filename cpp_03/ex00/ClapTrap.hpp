/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 01:30:00 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 12:29:23 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackPoints;
		ClapTrap();

	public:
		ClapTrap(std::string* newName);
		ClapTrap(std::string newName);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &copy);
		void attack(const std::string& target);
		void attack(const std::string* target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};


#endif //*****************************************CLAPTRAP_HPP