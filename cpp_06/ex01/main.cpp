/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:45:44 by aderugo           #+#    #+#             */
/*   Updated: 2023/05/05 23:51:16 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data		*data1;
	Data		*data2;
	uintptr_t	raw;

	data1 = new Data;
	data1->num = 1;
	data1->str = "Yalla";
	std::cout << "------data 1------" << std::endl;
	std::cout << "address: " << data1 << std::endl;
	std::cout << "int: " << data1->num << std::endl;
	std::cout << "str: " << data1->str << std::endl;
	std::cout << std::endl;

	raw = Serializer::serialize(data1);
	std::cout << "-----serialize-----" << std::endl;
	std::cout << "unsigned int: " << raw << std::endl;
	std::cout << std::endl;

	data2 = Serializer::deserialize(raw);
	std::cout << "-----deserialize-----" << std::endl;
	std::cout << "address: " << data2 << std::endl;
	std::cout << "int: " << data2->num << std::endl;
	std::cout << "str: " << data2->str << std::endl;

	delete data1;
	return (0);
}