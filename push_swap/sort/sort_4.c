/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:54:14 by aderugo           #+#    #+#             */
/*   Updated: 2022/09/03 00:36:15 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_4(t_node **a, t_node **b, t_move *move)
{
	move_to_top_min(move, a);
	reset_i(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
	free_list(a);
}
