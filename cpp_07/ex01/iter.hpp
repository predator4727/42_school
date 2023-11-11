/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 04:13:32 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/14 17:27:13 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *ar, size_t size, void (*f)(T const &) )
{
	for (size_t i=0; i < size; i++)
		f(ar[i]);
}

template <typename T>
void iter(T *ar, size_t size, void (*f)(T &) )
{
	for (size_t i=0; i < size; i++)
		f(ar[i]);
}

#endif //****************************ITER_HPP