/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:34:22 by aderugo           #+#    #+#             */
/*   Updated: 2023/07/01 17:37:12 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <exception>


class BitcoinExchange
{
	private:
		std::map<std::string, double> map;
		BitcoinExchange(const BitcoinExchange &copy);
    	BitcoinExchange &operator=(const BitcoinExchange &copy);
		
	public:
		BitcoinExchange();
    	~BitcoinExchange();
    	void processDataFile();
    	void processInputFile(const std::string &fileName);
    	bool checkDate(int y, int m, int d);
    	double convert(const std::string &date, double value);
};

#endif //***************BITCOINEXCHANGE_HPP