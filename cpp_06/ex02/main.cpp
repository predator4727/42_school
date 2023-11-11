/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:21:12 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/06 00:12:01 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	switch(std::rand() % 3)
	{
		case 0: return (new A);
		case 1: return (new B);
		case 2: return (new C);
	}
	return 0;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C";
}

void identify(Base& p) 
{ 
	try
	{
		Base& a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) { }
	try
	{
		Base& b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) { }
	try
	{
		Base& c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) { }
}


int main(void)
{
	for (int i = 0; i < 50; i++)
	{
		Base *obj = generate();
		std::cout << std::endl;
		std::cout << "Test " << i << ": ";
		identify(obj);
		std::cout << ", ";
		identify(*obj);
		if(obj)
			delete obj;
	}
	return (0);
}

//Dynamic_cast is a type-safe downcasting operator that is used to convert a pointer or reference 
//to a base class type to a pointer or reference to a derived class type. 
//The purpose of dynamic_cast is to check at runtime whether the object pointed to by the base class pointer can actually be converted to the derived class type. 
//If the object is of the derived class type, the dynamic_cast operator returns a valid pointer or reference to the derived class. 
//If not, the dynamic_cast operator returns a null pointer or throws a std::bad_cast exception, depending on the type of the cast expression used.