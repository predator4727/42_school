/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:00:16 by aderugo           #+#    #+#             */
/*   Updated: 2022/09/04 05:27:52 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_final_size(char **final_argv)
{
	int	i;

	i = 0;
	while (final_argv[i])
		i++;
	return (i);
}

int	space_check(char *str)
{
	int		i;
	int		sym_num;

	i = 0;
	sym_num = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			sym_num++;
		i++;
	}
	if (ft_strlen(str) == sym_num)
		return (1);
	return (0);
}

char	**get_arr(int argc, char **argv)
{
	int		i;
	char	*str;
	char	**arr;

	str = NULL;
	i = 1;
	if (argc == 2)
		arr = ft_split(argv[i], ' ');
	else
	{
		while (i < argc)
		{
			str = ft_strjoin_gnl(str, argv[i]);
			str = ft_strjoin_gnl(str, " ");
			i++;
		}
		arr = ft_split(str, ' ');
		free(str);
	}
	return (arr);
}

char	**get_final_argv(int argc, char **argv)
{
	int		i;
	char	**result;

	i = 1;
	while (argv[i])
	{
		if (space_check(argv[i]) == 0)
			argv[i] = ft_strtrim(argv[i], " ");
		i++;
	}
	if (argc == 2)
	{
		if (ft_isdigit(argv[1][0]) == 0 &&
				argv[1][0] != '-' && argv[1][0] != '+')
			error();
	}
	result = get_arr(argc, argv);
	return (result);
}

void	check_param(char **argv)
{
	int	i;
	int	k;

	i = 0;
	while (argv[++i] != NULL)
	{
		k = -1;
		while (argv[i][++k])
		{
			if (ft_isdigit(argv[i][k]) == 0)
			{
				if (argv[i][k] != '+' && argv[i][k] != '-' && argv[i][k] != ' ')
					error();
				if (ft_strlen(argv[i]) == 1 && (argv[i][k] == '+'
					|| argv[i][k] == '-'))
					error();
				if ((argv[i][k] == '+' || argv[i][k] == '-') &&
						(argv[i][k + 1] == '\0' || argv[i][k + 1] == '+' ||
							argv[i][k + 1] == '-' || argv[i][k + 1] == ' '))
					error();
			}
		}
	}
}
