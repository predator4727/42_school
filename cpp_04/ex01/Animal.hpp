/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:50:47 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 22:36:45 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal &copy);
		Animal &operator=(const Animal &copy);
		virtual	~Animal();
		virtual std::string getType() const;
		virtual void makeSound() const;
		virtual void setType(std::string type);
};

#endif //*****************************************ANIMAL_HPP