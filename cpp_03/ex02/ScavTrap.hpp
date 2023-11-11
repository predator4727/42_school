/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:56:52 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 12:49:42 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string* newName);
		ScavTrap(std::string newName);
		ScavTrap(const ScavTrap &copy);
		ScavTrap &operator=(const ScavTrap &copy);
		~ScavTrap();
		void attack(const std::string& target);
		void attack(const std::string* target);
		void guardGate();
};

#endif //******************************SCAVTRAP_HPP
