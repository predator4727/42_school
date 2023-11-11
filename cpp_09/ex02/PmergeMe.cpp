/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:34:44 by aderugo           #+#    #+#             */
/*   Updated: 2023/07/01 19:46:13 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	*this = copy;
    return;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
    if(this != &copy)
		return (*this);
	return (*this);
}

PmergeMe::~PmergeMe(){}

void PmergeMe::mergeInsertSort(std::vector<int>& nums) {
    if (nums.size() <= 1)
        return;

    std::vector<int> temp_vector(nums.size());

    for (size_t blockSize = 1; blockSize < nums.size(); blockSize *= 2) {
        for (size_t start = 0; start < nums.size(); start += 2 * blockSize) {
            size_t mid = start + blockSize;
            size_t end = std::min(start + 2 * blockSize, nums.size());

            size_t left = start;
            size_t right = mid;
            size_t index = start;

            while (left < mid && right < end) {
                if (nums[left] <= nums[right])
                    temp_vector[index++] = nums[left++];
                else
                    temp_vector[index++] = nums[right++];
            }

            while (left < mid)
                temp_vector[index++] = nums[left++];

            while (right < end)
                temp_vector[index++] = nums[right++];
        }

        std::copy(temp_vector.begin(), temp_vector.end(), nums.begin());
    }
}

void PmergeMe::mergeInsertSort(std::deque<int>& nums) {
    if (nums.size() <= 1)
        return;

    std::deque<int> temp_deque;

    for (size_t blockSize = 1; blockSize < nums.size(); blockSize *= 2) {
        for (size_t start = 0; start < nums.size(); start += 2 * blockSize) {
            size_t mid = start + blockSize;
            size_t end = std::min(start + 2 * blockSize, nums.size());

            size_t left = start;
            size_t right = mid;

            while (left < mid && right < end) {
                if (nums[left] <= nums[right])
                    temp_deque.push_back(nums[left++]);
                else
                    temp_deque.push_back(nums[right++]);
            }

            while (left < mid)
                temp_deque.push_back(nums[left++]);

            while (right < end)
                temp_deque.push_back(nums[right++]);

            std::copy(temp_deque.begin(), temp_deque.end(), nums.begin() + start);
            temp_deque.clear();
        }
    }
}



