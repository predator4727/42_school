/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:01:41 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/27 04:37:19 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <fstream>
# include "AForm.hpp"
# include <cstdlib>


class RobotomyRequestForm : public AForm {
	private:
		std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const std::string *target);
		RobotomyRequestForm(RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		virtual ~RobotomyRequestForm();
		
		std::string getTarget() const;
		void execute(Bureaucrat const & executor) const;
};


#endif //**************************************ROBOTOMY_REQUEST_FORM_HPP