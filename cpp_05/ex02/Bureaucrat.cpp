/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:56:00 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/27 06:17:52 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() 
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const std::string *newName, int grade): _grade(grade)
{
	std::cout << "Bureaucrat parametralized constructor called" << std::endl;
	if(newName == NULL || (*newName).empty()) {
		std::cout << "ERROR" << std::endl;
		exit(1);
		// throw std::invalid_argument("argument is either NULL or empty");
	}
	const_cast<std::string&>(this->_name) = *newName;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return;
}

Bureaucrat::Bureaucrat(const std::string &newName, int grade): _grade(grade)
{
	std::cout << "Bureaucrat parametralized constructor called" << std::endl;
	if(newName.empty()) {
		std::cout << "ERROR" << std::endl;
		exit(1);
		// throw std::invalid_argument("argument is empty");
	}
	const_cast<std::string&>(this->_name) = newName;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = copy;
	return;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &copy) {
		const_cast<std::string&>(this->_name) = copy.getName();
		this->_grade = copy._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat destructor called" << std::endl; }

const std::string &Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Grade is too high"; }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Grade is too low"; }

void Bureaucrat::incrementGrade(void)
{
	this->_grade -= 1;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade(void)
{
	this->_grade += 1;
	if(this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executes form " << form.getName() << std::endl;
		return ;
	}
	catch (AForm::CantExecuteForm &e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &copy) {
	out << copy.getName() << ", bureaucrat grade " << copy.getGrade() << std::endl;
	return (out);
}
