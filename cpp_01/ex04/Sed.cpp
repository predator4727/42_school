/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 02:51:51 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/15 20:49:21 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string filename): _filename(filename) { this->_filenameDst = this->_filename + ".replace"; }

Sed::~Sed() {}

void	Sed::replace( std::string s1, std::string s2 ) {
    std::string text;
	std::ifstream   ifs(this->_filename);
    std::ofstream   ofs(this->_filenameDst);
    if(!ifs.is_open()) {
        std::cerr << "Error: Could not open file" << std::endl;
        exit(1);
    } else {
        if (!std::getline(ifs, text, '\0')) 
            std::cerr << "Error: Empty file" << std::endl;
        else {
            size_t pos = text.find(s1);
            while(pos != std::string::npos) {
                text.erase(pos, s1.length());
                text.insert(pos, s2);
                pos = text.find(s1);
            }
            ofs << text;
        }
    ifs.close();
    ofs.close();
    } 
}
