/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:13:19 by aderugo           #+#    #+#             */
/*   Updated: 2022/09/03 00:38:10 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_node **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->data;
	y = (*a)->next->data;
	z = (*a)->next->next->data;
	if ((x > y) && (x < z) && (y < z))
		sa(*a, 1);
	else if ((x > y) && (y > z))
	{
		sa(*a, 1);
		rra(a, 1);
	}
	else if ((x > y) && (x > z) && (y < z))
		ra(a, 1);
	else if ((x < y) && (x < z) && (y > z))
	{
		sa(*a, 1);
		ra(a, 1);
	}
	else if ((x < y) && (x > z) && (y > z))
		rra(a, 1);
	free_list(a);
}
