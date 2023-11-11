/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:17:16 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/20 13:51:32 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N): _n(N) {
	return;
}

Span::Span(const Span &copy)
{
	*this = copy;
	return;
}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy) {
		this->_n = copy._n;
	}
	return (*this);
}

Span::~Span() { }

const char* Span::OverFilledSpanException::what() const throw() { return "ERROR: Span is already full"; } 

const char* Span::NotEnoughFilledSpanException::what() const throw() { return "ERROR : You need not less than 2 numbers to calculate span"; } 

void Span::addNumber(unsigned int number) {
        if (numbers.size() >= this->_n) {
            throw Span::OverFilledSpanException();
        }
        numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
        while (first != last) {
            Span::addNumber(*first);
            ++first;
        }
    }

int Span::shortestSpan() {
        if (numbers.size() <= 1) {
            throw Span::NotEnoughFilledSpanException();
        }
        std::vector<int> sorted(numbers);
        std::sort(sorted.begin(), sorted.end());
        int minSpan = sorted[1] - sorted[0];
        for (unsigned int i = 2; i < sorted.size(); i++) {
            int span = sorted[i] - sorted[i - 1];
            if (span < minSpan) {
                minSpan = span;
            }
        }
        return minSpan;
    }

int Span::longestSpan() {
        if (numbers.size() <= 1) {
            throw Span::NotEnoughFilledSpanException();
        }
        std::vector<int> sorted(numbers);
        std::sort(sorted.begin(), sorted.end());
		int maxSpan = sorted.back() - sorted.front();
        return maxSpan;
    }

