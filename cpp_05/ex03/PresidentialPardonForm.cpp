/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:06:31 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/27 06:09:27 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
	std::cout << "PPF default constructor called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 72, 45)
{
	std::cout << "PPF Constructor called" << std::endl;
    if(target.empty())
		throw std::invalid_argument("argument is empty");
    this->_target = target;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string *target): AForm("PresidentialPardonForm", 72, 45)
{
	std::cout << "PPF Constructor called" << std::endl;
    if(target == NULL || (*target).empty())
		throw std::invalid_argument("argument is either NULL or empty");
	this->_target = *target;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy): AForm("PresidentialPardonForm", 72, 45)
{
    std::cout << "PPF Copy constructor called" << std::endl;
    *this = copy;
    return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    std::cout << "PPF copy assignment operator called" << std::endl;
    if (this != &copy) {
        this->_target = copy._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() { std::cout << "PPF destructor called" << std::endl; }

std::string	PresidentialPardonForm::getTarget() const { return (this->_target); }

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->checkExec(executor);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}