/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 03:59:04 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/13 21:09:54 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T &min(T &a, T &b) {
	return ((a < b)? a : b);
}

template <typename T>
T &max(T &a, T &b) {
	return ((a > b)? a : b);
}
	
#endif //*****WHATEVER_HPP