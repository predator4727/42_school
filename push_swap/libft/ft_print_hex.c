/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:45:32 by aderugo           #+#    #+#             */
/*   Updated: 2022/07/15 15:41:44 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(unsigned int n, char c)
{
	int		len;
	char	*base;

	len = 1;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n > 15)
		len += ft_print_hex(n / 16, c);
	ft_print_char(base[n % 16]);
	return (len);
}
