/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:47:31 by aderugo           #+#    #+#             */
/*   Updated: 2022/02/05 21:14:21 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	int		i;
	size_t	k;

	i = 0;
	k = count * size;
	result = malloc(k);
	if (!result)
		return (NULL);
	while (k > 0)
	{
		((unsigned char *)result)[i] = '\0';
		i++;
		k--;
	}
	return (result);
}
