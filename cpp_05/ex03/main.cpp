/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:56:06 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/27 23:06:09 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	try {
		std::cout << std::endl;
		std::cout << std::endl;
		Intern		intern;
		Bureaucrat	paul("Paul", 3);
		AForm		*form;

		std::cout << std::endl;
		std::cout << std::endl;
		form = intern.makeForm("Welcome", "Vanya");
		if (form)
			delete form;
		std::cout << std::endl;
		std::cout << std::endl;
		form = intern.makeForm("presidential pardon", "Maynard");
		if (form)
			delete form;
		std::cout << std::endl;
		std::cout << std::endl;
		form = intern.makeForm("shrubbery creation", "Danny");
		if (form)
			delete form;
		std::cout << std::endl;
		std::cout << std::endl;
		form = intern.makeForm("robotomy request", "Adam");
		form->beSigned(paul);
		form->execute(paul);
		if (form)
			delete form;
		std::cout << std::endl;
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}