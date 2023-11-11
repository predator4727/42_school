/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:56:03 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/27 03:52:16 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept> 
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const 		std::string	_name;
		int			_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const &newName, int grade);
		Bureaucrat(std::string const *newName, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();
		const std::string &getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(Form &form) const;

	class GradeTooHighException: public std::exception { 
		public:
			virtual const char* what() const throw(); 
	};
	
	class GradeTooLowException: public std::exception { 
		public:
			virtual const char* what() const throw(); 
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &copy);

#endif //*********************************************BUREAUCRAT_HPP