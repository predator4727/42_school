/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:51:00 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 22:37:01 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _dogBrain;

	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &copy);
		virtual ~Dog();
		void makeSound() const;
		Brain	*getBrain() const;
};

#endif //*****************************************DOG_HPP