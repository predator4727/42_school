/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:04:46 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/15 01:36:40 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(){
	std::string text = "HI THIS IS BRAIN";
	std::string* stringPTR = &text;
	std::string& stringREF = text;

	std::cout << &text << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << text << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}