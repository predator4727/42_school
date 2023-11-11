/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 10:52:35 by aderugo           #+#    #+#             */
/*   Updated: 2022/02/02 18:13:11 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_long(unsigned long number, int sign)
{
	if (number >= 9223372036854775808UL && sign == -1)
		return (0);
	else if (number >= 9223372036854775807 && sign == 1)
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long	result;
	int				flag;

	result = 0;
	flag = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			flag = -1;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str++ - '0';
	}
	if (check_long(result, flag) == 0)
		return (0);
	else if (check_long(result, flag) == -1)
		return (-1);
	else
		result *= flag;
	return (result);
}
