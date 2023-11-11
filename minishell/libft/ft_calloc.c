/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 02:25:11 by numussan          #+#    #+#             */
/*   Updated: 2023/01/21 22:54:37 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*pointer;
	size_t	i;

	if (nitems == 0 || size == 0)
	{
		pointer = malloc(nitems * size);
		pointer[0] = '\0';
		return (pointer);
	}
	pointer = malloc(nitems * size);
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < nitems * size)
		pointer[i++] = '\0';
	return (pointer);
}
