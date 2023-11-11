/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 02:25:11 by numussan          #+#    #+#             */
/*   Updated: 2023/01/21 22:54:44 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(const char *str, int *i)
{
	if (str[*i] == '+')
	{
		*i = *i + 1;
		return (1);
	}
	if (str[*i] == '-')
	{
		*i = *i + 1;
		return (-1);
	}
	if (str[*i] < 48 || str[*i] > 57)
		return (0);
	if (str[*i] >= 48 || str[*i] <= 57)
		return (1);
	return (0);
}

int	ret_int(unsigned long integer, int flag)
{
	if (integer > 2147483647 && flag == 1)
		return (-1);
	if (integer > 2147483648 && flag == -1)
		return (0);
	if (flag == -1)
		integer *= -1;
	return (integer);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	integer;
	int				flag;

	integer = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	flag = ft_check(str, &i);
	if (flag == 0)
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
	{
		integer += (str[i] - '0');
		if (str[i + 1] >= 48 && str[i + 1] <= 57)
			integer *= 10;
		else
			break ;
		i++;
	}
	integer = ret_int(integer, flag);
	return (integer);
}
