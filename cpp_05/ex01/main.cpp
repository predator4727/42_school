/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:56:06 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/27 17:07:32 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat b1("Alice", 1);
		Bureaucrat b2("Bob", 150);
		Form f1("Form 1", 50, 100);
		Form f2("Form 2", 100, 50);

		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;

		std::cout << f2 << std::endl;
		b1.signForm(f2);
		std::cout << f2 << std::endl;

		std::cout << f1 << std::endl;
		b2.signForm(f1);
		std::cout << f1 << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() <<  std::endl;
	}
	return 0;
}