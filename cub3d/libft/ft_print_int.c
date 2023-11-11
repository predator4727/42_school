/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:45:19 by aderugo           #+#    #+#             */
/*   Updated: 2022/07/15 15:41:48 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_int(int n)
{
	int		len;

	len = 1;
	if (n == -2147483648)
		return (ft_print_string("-2147483648"));
	if (n < 0)
	{
		ft_print_char('-');
		len++;
		n = -n;
	}
	if (n > 9)
		len += ft_print_int(n / 10);
	ft_print_char(n % 10 + '0');
	return (len);
}
