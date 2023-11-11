/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:34:41 by aderugo           #+#    #+#             */
/*   Updated: 2023/07/01 19:43:49 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Error: No input provided." << std::endl;
        return 0;
    }

    PmergeMe pmergeme;

    std::vector<int> numsVector;
    std::deque<int> numsDeque;

    for (int i = 1; i < argc; ++i) {
        const char* input = argv[i];

            // Check if the input contains only digits
            for (int j = 0; input[j] != '\0'; ++j) {
                if (!isdigit(input[j])) {
                    if((input[j] == '+' || input[j] == '-') && isdigit(input[j+1]))
                        continue;
                    std::cerr << "Error: Invalid input format." << std::endl;
                    return 1;
                }
            }

            try {
                int num = std::atoi(argv[i]);
                if (num > 0 && num <= std::numeric_limits<int>::max()) {
                    numsVector.push_back(num);
                    numsDeque.push_back(num);
                } else {
                    std::cerr << "Error: Invalid positive integer encountered." << std::endl;
                    return 1;
                }
            } catch (const std::exception& e) {
                std::cerr << "Error: Invalid input format." << std::endl;
                return 1;
            }
    }

    std::cout << "Before: ";
    std::copy(numsVector.begin(), numsVector.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    clock_t startTimeVector = clock();
    pmergeme.mergeInsertSort(numsVector);
    clock_t endTimeVector = clock();

    clock_t startTimeDeque = clock();
    pmergeme.mergeInsertSort(numsDeque);
    clock_t endTimeDeque = clock();

    std::cout << "After: ";
    std::copy(numsVector.begin(), numsVector.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // std::cout << "After (Deque): ";
    // for (std::deque<int>::iterator it = numsDeque.begin(); it != numsDeque.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    double vectorTime = static_cast<double>(endTimeVector - startTimeVector) / (CLOCKS_PER_SEC / 1000000);
    double dequeTime = static_cast<double>(endTimeDeque - startTimeDeque) / (CLOCKS_PER_SEC / 1000000);

    std::cout << "Time to process a range of " << numsVector.size()
              << " elements with std::vector : " << vectorTime
              << " us" << std::endl;

    std::cout << "Time to process a range of " << numsDeque.size()
              << " elements with std::deque : " << dequeTime
              << " us" << std::endl;

    return 0;
}