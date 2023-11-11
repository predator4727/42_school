/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 09:41:59 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/27 21:40:53 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept> 
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:
		const 		std::string _name;
		bool 		_signed;
		const int 	_gradeSign;
		const int 	_gradeExecute;

	public:
		Form();
		Form(const std::string& name, int gradeSign, int gradeExecute);
		Form(const std::string* name, int gradeSign, int gradeExecute);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		virtual ~Form();
		const std::string& getName() const;
		bool isSigned() const;
		const int &getGradeSign() const;
		const int &getGradeExecute() const;
		void beSigned(Bureaucrat const & bureaucrat);
	
	class GradeTooHighException: public std::exception { 
		public:
			virtual const char* what() const throw(); 
	};
	
	class GradeTooLowException: public std::exception { 
		public:
			virtual const char* what() const throw(); 
	};
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif //*********************************************FORM_HPP
