/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:56:03 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/27 03:49:48 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <string>

class Bureaucrat
{
	private:
		const 		std::string	_name;
		int			_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& newName, int grade);
		Bureaucrat(const std::string* newName, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();
		const std::string &getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);

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