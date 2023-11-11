/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:17:13 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/18 19:07:10 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try {
        Span sp1 = Span(5);
        sp1.addNumber(6);
        sp1.addNumber(-3);
        sp1.addNumber(17);
        sp1.addNumber(9);
        sp1.addNumber(11);
        
        srand(time(0));
        Span sp2(10000);
        for (int i = 0; i < 10000; i++) {
            sp2.addNumber(static_cast<unsigned int>(std::rand()));
        }

        Span sp3(5);
        int arr[] = {5, 2, 8, 1, 10};
        std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));
        sp3.addNumbers(numbers.begin(), numbers.end());

        std::cout << "Shortest Span1: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest Span1: " << sp1.longestSpan() << std::endl;
        std::cout << "Shortest Span2: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest Span2: " << sp2.longestSpan() << std::endl;
        std::cout << "Shortest Span3: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest Span3: " << sp3.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}


