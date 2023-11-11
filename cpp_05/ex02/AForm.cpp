/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 09:41:56 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/27 21:47:18 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("default"), _signed(false), _gradeSign(1), _gradeExecute(1) 
{
	std::cout << "AForm default constructor called" << std::endl;
	return;
}

AForm::AForm(std::string name, int gradeSign, int gradeExecute): _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) 
{
    if(name.empty())
		throw std::invalid_argument("argument is empty");
	const_cast<std::string&>(this->_name) = name;
    if (gradeSign < 1 || gradeExecute < 1) {
        throw AForm::GradeTooHighException();
    }
    else if (gradeSign > 150 || gradeExecute > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(std::string *name, int gradeSign, int gradeExecute): _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) 
{
    if(name == NULL || (*name).empty())
		throw std::invalid_argument("argument is either NULL or empty");
	const_cast<std::string&>(this->_name) = *name;
    if (gradeSign < 1 || gradeExecute < 1) {
        throw AForm::GradeTooHighException();
    }
    else if (gradeSign > 150 || gradeExecute > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(const AForm &copy): _name("default"), _signed(false), _gradeSign(1), _gradeExecute(1) 
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = copy;
	return;
}

AForm &AForm::operator=(const AForm &copy)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &copy) {
        const_cast<std::string&>(this->_name) = copy.getName();
        this->_signed = copy.isSigned();
        const_cast<int&>(this->_gradeSign) = copy.getGradeSign();
        const_cast<int&>(this->_gradeExecute) = copy.getGradeExecute();
    }
    return(*this);
}

AForm::~AForm() { std::cout << "AForm destructor called" << std::endl; }

const std::string& AForm::getName() const { return this->_name; }

bool AForm::isSigned() const { return this->_signed; }

const int &AForm::getGradeSign() const { return this->_gradeSign; }

const int &AForm::getGradeExecute() const { return this->_gradeExecute; }

void AForm::beSigned(Bureaucrat const & bureaucrat) {
    if (bureaucrat.getGrade() <= this->_gradeSign) {
        this->_signed = true;
    } else {
        throw AForm::GradeTooLowException();
    }
}

void	AForm::checkExec(Bureaucrat const & executor) const
{
	if (!this->_signed || (executor.getGrade() > this->_gradeExecute))
		throw AForm::CantExecuteForm();
}

const char* AForm::GradeTooHighException::what() const throw() { return "Grade is too high"; }

const char* AForm::GradeTooLowException::what() const throw() { return "Grade is too low"; }

const char* AForm::CantExecuteForm::what() const throw() { return "can't execute, either form isn't signed or grade is too low"; }

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << "Form: " << form.getName() << ", ";
    out << "Signed: " << (form.isSigned() ? "Yes" : "No") << ", ";
    out << "Grade required to sign: " << form.getGradeSign() << ", ";
    out << "Grade required to execute: " << form.getGradeExecute();
    return out;
}
