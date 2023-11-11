/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:17:37 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/17 17:58:31 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <deque>
# include <stack>
# include <iterator>
# include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack<T> &copy);
		MutantStack &operator=(const MutantStack &copy);
		~MutantStack();

		typedef typename std::deque<T>::iterator iterator;
		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"

#endif //**********************************MUTANTSTACK_HPP