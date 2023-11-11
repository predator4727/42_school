/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:17:29 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/17 00:35:24 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {

    int arr[] = {10, 20, 30, 40, 50};
    int arr1[] = {1, 2, 3, 4, 5};
    
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::list<int> lst(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));

    try {
        std::vector<int>::iterator vecRes = easyfind(vec, 30);
        std::cout << "index in vec: " << std::distance(vec.begin(), vecRes) << std::endl;

        std::list<int>::iterator lstRes = easyfind(lst, 2);
        std::cout << "index in lst: " << std::distance(lst.begin(), lstRes) << std::endl;

        easyfind(vec, 60);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}