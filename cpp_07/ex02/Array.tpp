/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:40:38 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/14 17:40:09 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <class T>
Array<T>::Array(): _data(NULL), _size(0) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

template <class T>
Array<T>::Array(unsigned int n): _size(n) {
	std::cout << "Parametralized constructor called" << std::endl;
	this->_data = new T[_size];
	for (unsigned int i = 0; i < n; i++)
        _data[i] = T();
	return;
}

template <class T>
Array<T>::Array(const Array<T> & copy) {
	std::cout << "Copy contructor called" << std::endl;
    *this = copy;
    return;
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> & copy) {
	std::cout << "Copy assignement operator called" << std::endl;
    if (this != &copy) {
        this->_size = copy.size();
        this->_data = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; i++) {
            this->_data[i] = copy._data[i];
        }
    }
    return *this;
}

template <class T>
Array<T>::~Array() {
    delete[] this->_data;
	std::cout << "Destructor called" << std::endl;
	return;
}

template <class T>
T &Array<T>::operator[](unsigned int index) {
    if (index > this->_size - 1 || index < 0) {
        throw std::out_of_range("ERROR: Index is out of bounds");
    }
    return this->_data[index];
}

template <class T>
unsigned int Array<T>::size() const {
	return this->_size;
}

#endif //*****************************************************************ARRAY_TPP