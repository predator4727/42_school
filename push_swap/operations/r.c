/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:24:21 by aderugo           #+#    #+#             */
/*   Updated: 2022/07/31 04:26:54 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_node **a, int flag)
{
	t_node	*first;
	t_node	*last;
	t_node	*tmp;
	int		size;

	tmp = *a;
	size = ft_lstsize_ps(&tmp);
	if (size < 2)
		return ;
	last = ft_lstlast_ps(*a);
	first = *a;
	last->next = first;
	(*a) = first->next;
	first->next = NULL;
	if (flag == 1)
		ft_printf("ra\n");
}

void	rb(t_node **b, int flag)
{
	t_node	*first;
	t_node	*last;
	t_node	*tmp;
	int		size;

	tmp = *b;
	size = ft_lstsize_ps(&tmp);
	if (size < 2)
		return ;
	last = ft_lstlast_ps(*b);
	first = *b;
	last->next = first;
	(*b) = first->next;
	first->next = NULL;
	if (flag == 1)
		ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b, int flag)
{
	ra(a, flag);
	rb(b, flag);
	ft_printf("rr\n");
}
