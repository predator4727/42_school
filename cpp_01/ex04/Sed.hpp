/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 02:51:55 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/16 22:28:04 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>


class Sed {
	
	private:

		std::string _filename;
		std::string _filenameDst;

	public:

		Sed(std::string filename);
		~Sed();
		void	replace(std::string s1, std::string s2);
};

#endif //***********************************SED_HPP