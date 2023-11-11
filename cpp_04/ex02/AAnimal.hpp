/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:50:47 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 18:14:43 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:
		std::string type;

	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		AAnimal &operator=(const AAnimal &copy);
		virtual	~AAnimal();
		virtual std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif //*****************************************AANIMAL_HPP