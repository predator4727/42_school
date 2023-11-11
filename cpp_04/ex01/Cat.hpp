/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:50:53 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 20:38:14 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _catBrain;

	public:
		Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &copy);
		virtual ~Cat();
		void makeSound() const;
		Brain	*getBrain() const;
};

#endif //*****************************************CAT_HPP