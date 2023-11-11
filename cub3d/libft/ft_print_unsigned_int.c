/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:45:49 by aderugo           #+#    #+#             */
/*   Updated: 2022/07/15 15:41:57 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned_int(unsigned int n)
{
	int		len;

	len = 1;
	if (n > 9)
		len += ft_print_unsigned_int(n / 10);
	ft_print_char(n % 10 + '0');
	return (len);
}
