/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:51:03 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 22:41:50 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	// const WrongAnimal* n = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	// std::cout << n->getType() << " " << std::endl;
	// n->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	//delete n;
	delete i;
	delete j;
	delete meta;
	return 0;
}