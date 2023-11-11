/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:18:22 by aderugo           #+#    #+#             */
/*   Updated: 2022/01/30 16:16:18 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	int		i;

	result = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			result = &((char *)s)[i];
		i++;
	}
	if (c == '\0')
		result = &((char *)s)[i];
	return (result);
}
