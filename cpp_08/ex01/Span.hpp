/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:17:19 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/20 13:49:24 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <ctime>

class Span {
	private:
		std::vector<int> numbers;
		unsigned int _n;
		Span();
		
	public:
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();

		void addNumber(unsigned int num);
		
		void addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last);
		
		int shortestSpan();
		int longestSpan();
 
		class OverFilledSpanException : public std::exception {
			virtual const char* what() const throw(); 
		};

		class NotEnoughFilledSpanException : public std::exception {
			virtual const char* what() const throw(); 
		};
};

#endif //****SPAN_HPP