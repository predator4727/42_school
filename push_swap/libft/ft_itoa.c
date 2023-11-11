/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 00:35:25 by aderugo           #+#    #+#             */
/*   Updated: 2022/02/10 15:21:45 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_num(int n)
{
	int	i;

	i = 1;
	while (n != 0)
	{
		n /= 10;
		if (n != 0)
			i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		number;
	char	*num_str;

	neg = 0;
	number = count_num(n);
	if (n < 0)
		neg = 1;
	num_str = malloc((neg + number + 1) * sizeof(char));
	if (!num_str)
		return (0);
	num_str[neg + number] = '\0';
	while (number)
	{	
		if (neg)
			num_str[neg + number - 1] = -(n % 10) + '0';
		else if (!neg)
			num_str[neg + number - 1] = (n % 10) + '0';
		n /= 10;
		number--;
	}
	if (neg)
		num_str[0] = '-';
	return (num_str);
}
