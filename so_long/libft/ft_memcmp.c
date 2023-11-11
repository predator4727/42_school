/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:30:04 by aderugo           #+#    #+#             */
/*   Updated: 2022/02/02 18:36:18 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]))
		i++;
	if (i < n)
		return ((((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
	return (0);
}
