/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:46:28 by aderugo           #+#    #+#             */
/*   Updated: 2022/01/29 19:31:36 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		len_s1;

	len_s1 = ft_strlen(s1);
	dest = malloc((len_s1 + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s1, len_s1);
	dest[len_s1] = '\0';
	return (dest);
}
