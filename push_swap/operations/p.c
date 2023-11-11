/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:23:43 by aderugo           #+#    #+#             */
/*   Updated: 2022/09/03 08:44:22 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_node **a, t_node **b)
{
	int		size;
	t_node	*tmp;
	t_node	*temp;

	tmp = *b;
	temp = *b;
	size = ft_lstsize_ps(&tmp);
	if (size == 0)
		return ;
	push(a, temp->data, 0, temp->pos);
	del_node(b);
	ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b)
{
	int		size;
	t_node	*tmp;
	t_node	*temp;

	tmp = *a;
	temp = *a;
	size = ft_lstsize_ps(&tmp);
	if (size == 0)
		return ;
	push(b, temp->data, 0, temp->pos);
	del_node(a);
	ft_printf("pb\n");
}

void	pb_sm(t_node **a, t_node **b)
{
	int		size;
	t_node	*tmp;
	t_node	*temp;

	tmp = *a;
	temp = *a;
	size = ft_lstsize_ps(&tmp);
	if (size == 0)
		return ;
	push(b, temp->data, 0, temp->pos);
	ft_printf("pb\n");
}
