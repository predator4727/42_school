/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:30:48 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/22 21:39:53 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &copy);
		~Brain();
		std::string	getIdea(int i) const;
		std::string setIdea(int i, std::string idea);
		std::string setIdea(int i, std::string* idea);
};

#endif //*****************************************BRAIN_HPP