/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:34:36 by aderugo           #+#    #+#             */
/*   Updated: 2023/06/29 14:52:29 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &copy) {
	*this = copy;
	return;
}

RPN &RPN::operator=(const RPN &copy) {
	if(this != &copy)
		return (*this);
	return (*this);
}

RPN::~RPN(){}

bool isOperator(char token) {
    return (token == '+' || token == '-' || token == '*' || token == '/');
}

double getResult(double number1, double number2, char token) {
	switch(token) {
		case '+':
			return number1 + number2;
			break;
		case '-':
			return number1 - number2;
			break;
		case '*':
			return number1 * number2;
			break;
		case '/':
			if (number2 != 0) {
            	return number1 / number2;
			} else {
				std::cerr << "Error: Devision by zero." << std::endl;
				exit(1);
			}
			break;
	}
	return 1;
}

double RPN::calculate(std::string expression) {
    std::stack<double> stack;
    
    std::string::iterator it;
    for (it = expression.begin(); it != expression.end(); ++it) {
        if (*it != ' ' && !std::isdigit(*it) && !isOperator(*it)) {
            std::cerr << "Error: Invalid character encountered." << std::endl;
            exit(1);
        }
        // if (isdigit(*it)) {
        //     int number = *it - '0';
        //     stack.push(number);
		// if(isdigit(*(it + 1)) && *(it + 1) != '\0') {
		// 		std::cerr << "Error" << std::endl;
		// 		exit(1);
		// 	}
        if (std::isdigit(*it)) {
            int number = 0;
            while (std::isdigit(*it)) {
                number = number * 10 + (*it - '0');
                ++it;
            }
            --it;
			if(number < 0 || number > 9) {
				std::cerr << "Error: Number can't be more than 9 or less than 0." << std::endl;
            	exit(1);
			}
            stack.push(number);
        } else if (isOperator(*it)) {
            if (stack.size() < 2) {
                std::cerr << "Error: Insufficient numbers for operator." << std::endl;
                exit(1);
            }
            double number2 = stack.top();
            stack.pop();
            double number1 = stack.top();
            stack.pop();
            double result = getResult(number1, number2, *it);
            stack.push(result);
        }
    }

    if (stack.size() == 1) {
        return stack.top();
    } else {
        std::cerr << "Error: Invalid expression." << std::endl;
        exit(1);
    }
}