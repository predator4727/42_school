/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:21:23 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/12 19:24:59 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) {

	if(argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for(int i = 1; i < argc; i++)
		{
			std::string str(argv[i]);
			for(size_t j = 0; j < str.length(); j++)
				std::cout << (char) std::toupper(str[j]);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
