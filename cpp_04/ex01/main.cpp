/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:51:03 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 22:38:20 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    const int numAnimals = 100;
    Animal* animals[numAnimals];
    for (int i = 0; i < numAnimals; i++)
    {
        if (i < numAnimals / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        animals[i]->makeSound();
        std::cout << "index: " << i << std::endl;
    }
    for (int i = 0; i < numAnimals; i++) { delete animals[i]; }


    // stack
    // Dog dog1;
    // Dog dog2(dog1);
    // std::cout << dog1.getType() << std::endl;
    // std::cout << dog2.getType() << std::endl;
    // dog1.setType("dug");
    // std::cout << dog1.getType() << std::endl;
    // std::cout << dog2.getType() << std::endl;
    // dog1.setType("doog");
    // std::cout << dog1.getType() << std::endl;
    // std::cout << dog2.getType() << std::endl;


    // heap
    // Dog* dog1 = new Dog;
    // Dog* dog2 = new Dog(*dog1);
    // std::cout << dog1->getType() << std::endl;
    // std::cout << dog2->getType() << std::endl;
    // dog1->setType("dug");
    // std::cout << dog1->getType() << std::endl;
    // std::cout << dog2->getType() << std::endl;
    // dog1->setType("doog");
    // std::cout << dog1->getType() << std::endl;
    // std::cout << dog2->getType() << std::endl;
    // delete (dog1);
    // delete (dog2);
	
    
	// Dog *dog1 = new Dog();
	// std::cout << "\n\n------------------[1]-----------------" << std::endl;
	// dog1->getBrain()->setIdea(0, "I'm a dog");
	// std::cout << "Ideas of dog1: " << dog1->getBrain()->getIdea(0) << std::endl;
	// std::cout << "------------------[2]-----------------" << std::endl;
	// Dog *dog2 = new Dog(*dog1);
	// std::cout << "\nIdeas of dog2: " << dog2->getBrain()->getIdea(0) << std::endl;
	// std::cout << "------------------[3]-----------------" << std::endl;
	// dog1->getBrain()->setIdea(0, "I am a Wierd dog");
	// std::cout << "Ideas of dog1: " << dog1->getBrain()->getIdea(0) << std::endl;
	// std::cout << "Ideas of dog2: " << dog2->getBrain()->getIdea(0) << std::endl;
	// std::cout << "--------------------------------------" << std::endl;
	// delete (dog1);
	// delete (dog2);

	return 0;
}