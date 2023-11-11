/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:40:45 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/14 17:41:13 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    try {
        Array<int> x(10);
        for (unsigned int i = 0; i < x.size(); i++) {
            x[i] = i;
            std::cout << x[i] << " ";
        }
        std::cout << std::endl;
        Array<int> y = x;
        y[3] = 6;
        for (unsigned int i = 0; i < x.size(); i++) {
            std::cout << x[i] << " ";
        }
        std::cout << std::endl;
        for (unsigned int i = 0; i < y.size(); i++) {
            std::cout << y[i] << " ";
        }
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}


