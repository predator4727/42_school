/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:24:33 by aderugo           #+#    #+#             */
/*   Updated: 2022/09/03 09:43:37 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node *a, int flag)
{
	int		temp;
	int		size;
	t_node	*tmp;

	tmp = a;
	size = ft_lstsize_ps(&tmp);
	if (size < 2)
		return ;
	temp = a->data;
	a->data = a->next->data;
	a->next->data = temp;
	temp = a->pos;
	a->pos = a->next->pos;
	a->next->pos = temp;
	if (flag == 1)
		ft_printf("sa\n");
}

void	sb(t_node *b, int flag)
{
	int		temp;
	int		size;
	t_node	*tmp;

	tmp = b;
	size = ft_lstsize_ps(&tmp);
	if (size < 2)
		return ;
	temp = b->data;
	b->data = b->next->data;
	b->next->data = temp;
	temp = b->pos;
	b->pos = b->next->pos;
	b->next->pos = temp;
	if (flag == 1)
		ft_printf("sb\n");
}

void	ss(t_node *a, t_node *b, int flag)
{
	sa(a, flag);
	sb(b, flag);
	ft_printf("ss\n");
}
