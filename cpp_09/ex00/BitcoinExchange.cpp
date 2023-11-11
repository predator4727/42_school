/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:34:19 by aderugo           #+#    #+#             */
/*   Updated: 2023/07/01 17:43:48 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & copy) {
    *this = copy;
    return;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange & copy) {
    if(this != &copy)
        this->map = copy.map;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::processDataFile() {
    std::string line;
    bool firstLine = false;
    std::ifstream dataFile("data.csv");
    if (!dataFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        exit(1);
    }
    while (std::getline(dataFile, line)) {
        if (firstLine) {
            size_t commaPos = line.find(',');
            if (commaPos != std::string::npos) {
                std::string date = line.substr(0, commaPos);
                std::string value = line.substr(commaPos + 1);
                this->map[date] = std::atof(value.c_str());
            }
        } else {
            firstLine = true;
        }
    }
    dataFile.close();
}

bool BitcoinExchange::checkDate(int y, int m, int d) {
    if (y < 2009) return false;
    if (m == 2 && d > 29) return false;
    if ((m == 2) && (d > 28) && ((y % 4 != 0) \
            || ((y % 4 == 0) && (y % 100 == 0) && (y % 400 != 0)))) return false;
    if (d < 1 || d > 31) return false;
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d == 31) return false;
    return true;
}

double BitcoinExchange::convert(const std::string &date, double value) {
    if (value < 0) return -1;
    if (value > 1000) return -2;
    std::map<std::string, double>::iterator it = this->map.lower_bound(date);
    if (it != this->map.begin() && it->first != date)
        --it;
    return value * it->second;
}

void BitcoinExchange::processInputFile(const std::string &fileName) {
    std::string line;
    bool firstLine = false;
    std::ifstream inputFile(fileName.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        exit(1);
    }
    while (std::getline(inputFile, line)) {
        if (firstLine) {
            size_t delimiterPos = line.find('|');
            if (delimiterPos != std::string::npos) {
                std::string date = line.substr(0, delimiterPos);
                std::string value = line.substr(delimiterPos + 2);
                std::string y = date.substr(0, 4);
                std::string m = date.substr(5, 2);
                std::string d = date.substr(8);
                if (BitcoinExchange::checkDate(std::atoi(y.c_str()), std::atoi(m.c_str()), std::atoi(d.c_str()))) {
                    double totalValue = BitcoinExchange::convert(date, std::atof(value.c_str()));
                    if (totalValue == -1) {
                        std::cerr << "Error: not a positive number." << std::endl;
                    } else if (totalValue == -2) {
                        std::cerr << "Error: too large a number." << std::endl;
                    } else {
                        std::cout << date << " => " << value << " = " << totalValue << std::endl;
                    }
                } else {
                    std::cerr << "Error: bad input => " << date << std::endl;
                }
            } else {
                std::cerr << "Error: bad input => " << line << std::endl;
            }
        } else {
            firstLine = true;
        }
    }
    inputFile.close();
}
