/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:06:33 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/27 06:10:02 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{
	std::cout << "RRF default constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "SCF Constructor called" << std::endl;
    if(target.empty())
		throw std::invalid_argument("argument is empty");
    this->_target = target;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string *target): AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "SCF Constructor called" << std::endl;
    if(target == NULL || (*target).empty())
		throw std::invalid_argument("argument is either NULL or empty");
	this->_target = *target;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy): AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << "RRF Copy constructor called" << std::endl;
    *this = copy;
    return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    std::cout << "RRF copy assignment operator called" << std::endl;
    if (this != &copy) {
        this->_target = copy._target;
    }
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() { std::cout << "RRF destructor called" << std::endl; }

std::string	RobotomyRequestForm::getTarget() const { return (this->_target); }

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->checkExec(executor);
    std::cout << "* Drill noises *\n";
        if (std::rand() % 2 == 0) {
            std::cout << this->_target << " has been robotomized successfully.\n";
        } else {
            std::cout << "Robotomy failed on " << this->_target << ".\n";
        }
}