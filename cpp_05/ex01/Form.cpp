/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 09:41:56 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/27 21:41:29 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("default"), _signed(false), _gradeSign(1), _gradeExecute(1) 
{
	std::cout << "Form default constructor called" << std::endl;
	return;
}

Form::Form(const std::string* name, const int gradeSign, const int gradeExecute): _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) 
{
    if(name == NULL || (*name).empty())
		throw std::invalid_argument("argument is either NULL or empty");
	const_cast<std::string&>(this->_name) = *name;
    if (gradeSign < 1 || gradeExecute < 1) {
        throw Form::GradeTooHighException();
    }
    else if (gradeSign > 150 || gradeExecute > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const std::string& name, const int gradeSign, const int gradeExecute): _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) 
{
    if(name.empty())
		throw std::invalid_argument("argument is empty");
	const_cast<std::string&>(this->_name) = name;
    if (gradeSign < 1 || gradeExecute < 1) {
        throw Form::GradeTooHighException();
    }
    else if (gradeSign > 150 || gradeExecute > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form &copy): _name("default"), _signed(false), _gradeSign(1), _gradeExecute(1)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = copy;
	return;
}

Form &Form::operator=(const Form &copy)
{
	std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &copy) {
        const_cast<std::string&>(this->_name) = copy.getName();
        this->_signed = copy.isSigned();
        const_cast<int&>(this->_gradeSign) = copy.getGradeSign();
        const_cast<int&>(this->_gradeExecute) = copy.getGradeExecute();
    }
	return (*this);
}

Form::~Form() { std::cout << "Form destructor called" << std::endl; }

const std::string& Form::getName() const { return this->_name; }

bool Form::isSigned() const { return this->_signed; }

const int &Form::getGradeSign() const { return this->_gradeSign; }

const int &Form::getGradeExecute() const { return this->_gradeExecute; }

void Form::beSigned(Bureaucrat const & bureaucrat) {
    if (bureaucrat.getGrade() <= this->_gradeSign) {
        this->_signed = true;
    } else {
        throw Form::GradeTooLowException();
    }
}

const char* Form::GradeTooHighException::what() const throw() { return "Grade is too high"; }

const char* Form::GradeTooLowException::what() const throw() { return "Grade is too low"; }

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Form: " << form.getName() << ", ";
    out << "Signed: " << (form.isSigned() ? "Yes" : "No") << ", ";
    out << "Grade required to sign: " << form.getGradeSign() << ", ";
    out << "Grade required to execute: " << form.getGradeExecute();
    return out;
}
