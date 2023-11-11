/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 02:51:47 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/15 17:28:20 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main (int argc, char **argv)
{
    if (argc == 4) {
        std::string filename = argv[1];
        std::string s1 = argv[2];
        std::string s2 = argv[3];
        Sed sed(filename);
        sed.replace(s1, s2);
    } else {
        std::cerr << "Usage: ./Sed <filename> <s1> <s2>." << std::endl;
        return 1;
    }
    return 0;
}