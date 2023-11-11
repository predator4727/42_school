/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:30:53 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 22:33:25 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
        this->_ideas[i] = "Default idea";
    }
	return;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
        this->_ideas[i] = copy._ideas[i];
    }
	return;
}

Brain &Brain::operator=(const Brain &copy)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &copy) {
        for (int i = 0; i < 100; i++) {
            this->_ideas[i] = copy._ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

std::string	Brain::getIdea(int i) const 
{ 
    if(0 <= i && i < 100)
        return (this->_ideas[i]);
    else
    {
        std::cout <<"Default idea" << std::endl;
        std::cerr <<"Error: Idea index must be between 0 and 99" << std::endl;
        return "";
    }
}

std::string Brain::setIdea(int i, std::string idea)
{
    if(idea.empty()) {
		std::cerr << "Error: idea name" << std::endl;
        return "";
	}
    if(0 > i || i >= 100)
    {
        std::cout <<"Default idea" << std::endl;
        std::cerr << "Error: Idea index must be between 0 and 99" << std::endl;
        return "";
    }
	this->_ideas[i] = idea;
	return (this->_ideas[i]);
}

std::string Brain::setIdea(int i, std::string* idea)
{
    if(idea == NULL || (*idea).empty()) {
		std::cerr << "Error: idea name" << std::endl;
        return "";
    }
    if(0 > i || i >= 100)
    {
        std::cout <<"Default idea" << std::endl;
        std::cerr << "Error: Idea index must be between 0 and 99" << std::endl;
        return "";
    }
	this->_ideas[i] = *idea;
	return (this->_ideas[i]);
}
