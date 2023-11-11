/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:22:32 by aderugo           #+#    #+#             */
/*   Updated: 2022/07/01 13:03:52 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	operation_quot(const char *s, int start, int finish)
{
	start++;
	finish++;
	printf("%d", finish);
	while (s[finish] != '"')
		finish++;
	finish--;
	return (finish);
}

static size_t	word_counter(const char *s, char c)
{
	size_t	flag;
	size_t	counter;

	flag = 0;
	counter = 0;
	while (*s != '\0')
	{
		if (*s != c && !flag)
		{
			counter++;
			flag = 1;
			if (*s == '"')
			{
				s++;
				while (*s != '"')
					s++;
				break ;
			}
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (counter);
}

static void	copy_to_arr(char **arr, const char *str, char c)
{
	int		start;
	int		finish;
	int		i;

	finish = -1;
	start = -1;
	i = 0;
	while ((++finish) <= ft_strlen(str))
	{
		if (str[finish] != c && start == -1)
		{
			start = finish;
			if (str[start] == '"')
				finish = operation_quot(str, ++start, finish);
		}
		else if ((str[finish] == c || finish == ft_strlen(str)) && start != -1)
		{
			if (str[finish - 1] == '"')
				arr[i] = ft_substr(str, start, --finish - start);
			arr[i] = ft_substr(str, start, finish - start);
			start = -1;
			i++;
		}
	}
	arr[i] = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((word_counter(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	copy_to_arr(arr, s, c);
	return (arr);
}
