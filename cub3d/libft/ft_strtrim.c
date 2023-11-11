/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:28:30 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/03 03:47:54 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	size_t	s1_end;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s1_end = ft_strlen(s1);
	while (s1_end && ft_strchr(set, s1[s1_end]))
		s1_end--;
	return (ft_substr(s1, 0, s1_end + 1));
}
