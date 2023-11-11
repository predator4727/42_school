/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:34:32 by aderugo           #+#    #+#             */
/*   Updated: 2023/06/29 15:24:10 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char* argv[]) {
	try {
		if (argc < 2) {
			std::cout << "Error" << std::endl;
			return 1;
    	}
		std::cout << RPN::calculate(argv[1]) << std::endl;
		return 0;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}