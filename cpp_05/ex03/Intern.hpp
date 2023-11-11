/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:00:58 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/27 21:05:23 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &copy );
		Intern	&operator=(const Intern &copy);
		~Intern();

		AForm	*makeForm(const std::string &formName, const std::string &target) const;
		// AForm	*makeForm(const std::string *formName, const std::string *target) const;
		// AForm	*makeForm(const std::string &formName, const std::string *target) const;
		// AForm	*makeForm(const std::string *formName, const std::string &target) const;
};

#endif // ********************************************************************INTERN_HPP