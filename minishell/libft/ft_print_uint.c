/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 02:25:11 by numussan          #+#    #+#             */
/*   Updated: 2023/01/21 22:57:21 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_uint(unsigned int nbr)
{
	char	c;
	int		length;

	length = 0;
	if (nbr == 4294967295)
	{
		write(1, "4294967295", 10);
		return (10);
	}
	if (nbr >= 10)
		length += ft_print_uint(nbr / 10);
	c = (nbr % 10) + '0';
	length += ft_print_char(c);
	return (length);
}
