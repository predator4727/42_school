/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:51:00 by aderugo           #+#    #+#             */
/*   Updated: 2022/02/10 16:59:35 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[i] != '\0' && i < len)
	{
		k = 0;
		while (haystack[i + k] != '\0'
			&& haystack[i + k] == needle[k] && (i + k) < len)
		{
			if (needle[k + 1] == '\0')
			{
				return ((char *)&haystack[i]);
			}
			++k;
		}
		++i;
	}
	return (0);
}
