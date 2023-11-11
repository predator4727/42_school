/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:34:15 by aderugo           #+#    #+#             */
/*   Updated: 2023/06/29 16:47:42 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
	try {
		BitcoinExchange bitEx;
		if (argc != 2) {
			std::cout << "Error: could not open file." << std::endl;
			return 1;
		}
		bitEx.processDataFile();
		bitEx.processInputFile(argv[1]);
		return 0;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}