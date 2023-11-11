/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:47:02 by aderugo           #+#    #+#             */
/*   Updated: 2022/09/04 08:51:46 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi_ps(char *str, char **final_argv, int *arr, int index)
{
	long	result;
	int		flag;

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
	if (ft_isdigit(*str) == 0 && *str)
		free_error_complex(arr, final_argv, index);
	if (result > INT_MAX && flag == 1)
		free_error_complex(arr, final_argv, index);
	if (((result - 1) > INT_MAX) && flag == -1)
		free_error_complex(arr, final_argv, index);
	result *= flag;
	return (result);
}
