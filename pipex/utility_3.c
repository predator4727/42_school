/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:47:10 by aderugo           #+#    #+#             */
/*   Updated: 2022/06/30 20:57:51 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		k = 0;
		while (haystack[i + k] != '\0'
			&& haystack[i + k] == needle[k] && (i + k) < len)
		{
			if (needle[k + 1] == '\0')
				return ((char *)&haystack[i]);
			++k;
		}
		++i;
	}
	return (0);
}

void	args_check(char *str)
{
	int		i;
	int		sym_num;

	i = 0;
	sym_num = 0;
	while (str[i] != 0)
	{
		if (str[i] == ' ')
			sym_num++;
		i++;
	}
	if (ft_strlen(str) == sym_num)
		exit(1);
}
