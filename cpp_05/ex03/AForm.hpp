/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 09:41:59 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/27 21:49:06 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept> 
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:
		const		std::string _name;
		bool 		_signed;
		const int 	_gradeSign;
		const int 	_gradeExecute;

	public:
		AForm();
		AForm(std::string name, int gradeSign, int gradeExecute);
		AForm(std::string *name, int gradeSign, int gradeExecute);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		virtual ~AForm();
		const std::string& getName() const;
		bool isSigned() const;
		const int &getGradeSign() const;
		const int &getGradeExecute() const;
		void beSigned(Bureaucrat const & bureaucrat);
		void checkExec(Bureaucrat const & executor) const;
		virtual void execute(Bureaucrat const & executor) const = 0;
	
	class GradeTooHighException: public std::exception { 
		public:
			virtual const char* what() const throw(); 
	};
	
	class GradeTooLowException: public std::exception { 
		public:
			virtual const char* what() const throw(); 
	};

	class CantExecuteForm : public std::exception {
		public:
			virtual const char * what () const throw ();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif //***************************************************************AFORM_HPP
