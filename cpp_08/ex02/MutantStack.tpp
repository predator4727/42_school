/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:17:40 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/17 17:59:36 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() { return; }

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> & copy) {
    *this = copy;
    return;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> & copy) {
    if (this != &copy) {
        return *this;
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() { return; }

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return std::stack<T>::c.begin(); 
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return std::stack<T>::c.end(); 
}

#endif //***************************************************MUTANTSTACK_TPP