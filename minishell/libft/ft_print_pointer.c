/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 02:25:11 by numussan          #+#    #+#             */
/*   Updated: 2023/01/21 22:57:08 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pointer_helper(intptr_t num)
{
	int		length;
	int		reminder;
	char	symbol;

	reminder = 0;
	length = 0;
	reminder = num % 16;
	if (reminder < 10)
		symbol = reminder + '0';
	else
		symbol = reminder - 10 + 'a';
	if (num >= 16)
		length += ft_pointer_helper(num / 16);
	length += ft_print_char(symbol);
	return (length);
}

int	ft_print_pointer(unsigned long ptr)
{
	int	length;

	write(1, "0x", 2);
	length = 2;
	if (ptr == 0)
		length += ft_print_char('0');
	else
		length += ft_pointer_helper(ptr);
	return (length);
}
