/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:04:18 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/27 04:38:57 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_REQUEST_FORM_HPP
# define PRESIDENTIAL_REQUEST_FORM_HPP

# include <fstream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const std::string *target);
		PresidentialPardonForm(PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
		virtual ~PresidentialPardonForm();
		
		std::string getTarget() const;
		void execute(Bureaucrat const & executor) const;
};


#endif //**************************************ROBOTOMY_REQUEST_FORM_HPP