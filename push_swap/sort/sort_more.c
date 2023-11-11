/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:11:03 by aderugo           #+#    #+#             */
/*   Updated: 2022/09/03 08:39:34 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_back(t_node **a, t_node **b)
{
	int		size_b;
	t_move	move;

	size_b = ft_lstsize_ps(b);
	while (size_b > 0)
	{
		move_to_top_max(&move, b);
		pa(a, b);
		size_b--;
	}
	free_list(a);
}

void	sort_more(t_node **a, t_node **b, t_move *move, int *arr)
{
	t_node	*start_a;

	start_a = *a;
	while (arr[1] > 0)
	{
		if (start_a->pos <= arr[0])
		{
			move_to_top_cur(move, a, start_a->pos);
			pb_sm(a, b);
			if (start_a->pos < (arr[0] - (arr[2] / 2)))
				rb(b, 1);
			start_a = start_a->next;
			del_node(a);
			arr[1]--;
		}
		else
			start_a = start_a->next;
		if (start_a == NULL)
		{
			start_a = *a;
			arr[0] += arr[2];
		}
	}
	push_back(a, b);
}
