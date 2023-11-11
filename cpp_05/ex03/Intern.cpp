/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:00:55 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/27 23:05:41 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
	return;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
	return;
}

Intern &Intern::operator=(const Intern &copy)
{
	std::cout << "Intern assignement operator called" << std::endl;
	if (this == &copy)
        return *this;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
	return;
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target) const
{
	if(formName.empty() || target.empty())
		throw std::invalid_argument("argument is empty");
	std::string forms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm	*form = NULL;

	for (int i = 0; i < 3; i++)
	{
        if (formName == forms[i])
		{
			switch(i) 
			{
				case 0:
					form = new PresidentialPardonForm(target);
					break;
				case 1:
				    form = new RobotomyRequestForm(target);
					break;
				case 2:
					form = new ShrubberyCreationForm(target);
					break;
			}
		}
	}
	if (form == NULL)
		std::cout << "Intern " << formName << " form doesn't exist" << std::endl;
	else
		std::cout << "Intern creates " << formName << std::endl;
	return form;
}

