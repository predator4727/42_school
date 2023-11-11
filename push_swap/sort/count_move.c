/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:35:58 by aderugo           #+#    #+#             */
/*   Updated: 2022/09/01 07:34:18 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_move(t_move *move, int size, int index)
{
	int	top;
	int	bottom;

	top = index - 1;
	bottom = size - index + 1;
	if (top < bottom)
	{
		move->step = top;
		move->route = 1;
	}
	else
	{
		move->step = bottom;
		move->route = 0;
	}
	return (move->step);
}
