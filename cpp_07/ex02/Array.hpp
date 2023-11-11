/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:40:35 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/14 15:44:17 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <class T>
class Array {
	private:
		T* _data;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &copy);
		Array &operator=(const Array &copy);
		~Array();

		T& operator[](unsigned int index);
		unsigned int size() const;
};

#include "Array.tpp"

#endif //*************************************ARRAY_HPP

