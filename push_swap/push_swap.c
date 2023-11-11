/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:45:07 by aderugo           #+#    #+#             */
/*   Updated: 2022/09/04 05:56:15 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dirty_check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (ft_strlen(argv[i]) == 0 || space_check(argv[i]) == 1)
				error();
			i++;
		}
	}
}

void	prepare_and_sort(t_node *a, t_node *b, char **final_argv, int size)
{
	int		*arr;
	int		i;

	arr = malloc(size * sizeof(int));
	i = -1;
	while (++i < size)
	{
		arr[i] = ft_atoi_ps(final_argv[i], final_argv, arr, i);
		free(final_argv[i]);
	}
	i = size - 1;
	while (i >= 0)
		push(&a, arr[i--], 0, 0);
	reset_i(&a);
	if (check_dubl(arr, size) == 1)
	{
		free_complex(arr, final_argv);
		free_list(&a);
		error();
	}
	sort_int_arr(arr, size);
	set_pos(&a, arr, size);
	free_complex(arr, final_argv);
	list_sort(a, b, size);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		size;
	char	**final_argv;

	a = NULL;
	b = NULL;
	dirty_check(argc, argv);
	check_param(argv);
	final_argv = get_final_argv(argc, argv);
	free_argv(argv);
	if (!final_argv)
		return (0);
	size = get_final_size(final_argv);
	prepare_and_sort(a, b, final_argv, size);
	return (0);
}
