/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:56:33 by aderugo           #+#    #+#             */
/*   Updated: 2022/09/03 10:48:43 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	chunk_count(int size_a)
{
	if (size_a <= 250)
		return (30);
	else
		return (50);
}

void	list_sort(t_node *a, t_node *b, int size)
{
	t_move	move;
	int		arr[3];

	ft_bzero(arr, 3);
	if (check_sort(&a) == 0)
	{
		free_list(&a);
		exit(1);
	}
	b = NULL;
	if (size == 2)
		sort_2(&a);
	else if (size == 3)
		sort_3(&a);
	else if (size == 4)
		sort_4(&a, &b, &move);
	else if (size == 5)
		sort_5(&a, &b, &move);
	else
	{
		arr[0] = chunk_count(ft_lstsize_ps(&a));
		arr[1] = ft_lstsize_ps(&a);
		arr[2] = arr[0];
		sort_more(&a, &b, &move, arr);
	}
}
