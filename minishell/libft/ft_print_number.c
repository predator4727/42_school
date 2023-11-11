/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 02:25:11 by numussan          #+#    #+#             */
/*   Updated: 2023/01/21 22:57:04 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_number(int nbr)
{
	char	c;
	int		length;

	length = 0;
	if (nbr == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		length += ft_print_char('-');
		nbr *= -1;
	}
	if (nbr >= 10)
		length += ft_print_number(nbr / 10);
	c = nbr % 10 + '0';
	length += ft_print_char(c);
	return (length);
}
