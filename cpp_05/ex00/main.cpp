/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:56:06 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/27 16:52:09 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		// normal state behavior test1
		Bureaucrat	test1("TEST1", 38);
		std::cout << test1;
		test1.decrementGrade();
		std::cout << test1;
		test1.incrementGrade();
		std::cout << test1;
		test1.incrementGrade();
		std::cout << test1;

		// high-level border test2
		Bureaucrat	test2("TEST2", 1);
		std::cout << test2;
		test2.incrementGrade();

		// low-level border test3
		Bureaucrat	test3("TEST3", 150);
		std::cout << test3;
		test3.decrementGrade();
		
		// behind of high-level border test4
		Bureaucrat	test4("TEST4", 0);
		std::cout << test4;
		test4.decrementGrade();
		
		// behind of low-level border test5
		Bureaucrat	test5("TEST5", 151);
		std::cout << test5;
		test5.incrementGrade();
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() <<  std::endl;
	}
	return 0;
}