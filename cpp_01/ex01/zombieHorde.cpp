/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:35:38 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/16 21:58:14 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie* zombieHord = new Zombie[N];
	for(int n = 0; n < N; n++) {
		zombieHord[n].setName(name);
		zombieHord[n].announce();
	}
	return zombieHord;
}