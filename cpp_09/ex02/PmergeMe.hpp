/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:34:47 by aderugo           #+#    #+#             */
/*   Updated: 2023/07/01 19:45:07 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>


class PmergeMe
{
	private:
		PmergeMe(const PmergeMe &copy);
    	PmergeMe &operator=(const PmergeMe &copy);
	public:
		PmergeMe();
    	~PmergeMe();
		
		void mergeInsertSort(std::vector<int>& nums);
		void mergeInsertSort(std::deque<int>& nums);
};

#endif //***************PMERGEME_HPP