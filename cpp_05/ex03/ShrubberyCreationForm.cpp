/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:06:37 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/27 23:12:40 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
	std::cout << "SCF default constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "SCF Constructor called" << std::endl;
    if(target.empty())
		throw std::invalid_argument("argument is empty");
    this->_target = target;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string *target): AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "SCF Constructor called" << std::endl;
    if(target == NULL || (*target).empty())
		throw std::invalid_argument("argument is either NULL or empty");
	this->_target = *target;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy): AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "SCF Copy constructor called" << std::endl;
    *this = copy;
    return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    std::cout << "SCF copy assignment operator called" << std::endl;
    if(this != &copy) {
        this->_target = copy._target;
    }
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() { std::cout << "SCF destructor called" << std::endl; }

std::string	ShrubberyCreationForm::getTarget() const { return (this->_target); }

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->checkExec(executor);
    std::ofstream	file;
	std::string		fileName = this->_target + "_shrubbery";
    file.open(fileName.c_str());
    file    << "    oxoxoo    ooxoo" << std::endl
            << "  ooxoxo oo  oxoxooo" << std::endl
            << " oooo xxoxoo ooo ooox" << std::endl
            << " oxo o oxoxo  xoxxoxo" << std::endl
            << "  oxo xooxoooo o ooo" << std::endl
            << "    ooo\\oo\\  /o/o" << std::endl
            << "        \\  \\/ /" << std::endl
            << "         |   /" << std::endl
            << "         |  |" << std::endl
            << "         | D|" << std::endl
            << "         |  |" << std::endl
            << "         |  |" << std::endl
            << "  ______/____\\____" << std::endl;
	file.close();
    std::cout << "tree was saved in file" << std::endl;
}

