/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_limit_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:30:49 by aderugo           #+#    #+#             */
/*   Updated: 2022/08/26 20:12:14 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max_node(t_node **head)
{
	int		max_node;
	t_node	*current;

	max_node = (*head)->data;
	current = *head;
	while (current != NULL)
	{
		if (max_node < current->data)
			max_node = current->data;
		current = current->next;
	}	
	return (max_node);
}

int	find_min_node(t_node **head)
{
	int		min_node;
	t_node	*current;

	min_node = (*head)->data;
	current = *head;
	while (current != NULL)
	{
		if (min_node > current->data)
			min_node = current->data;
		current = current->next;
	}	
	return (min_node);
}
