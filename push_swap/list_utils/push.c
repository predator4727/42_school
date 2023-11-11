/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:15:07 by aderugo           #+#    #+#             */
/*   Updated: 2022/09/03 08:44:06 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_node **head, int data, int index, int pos)
{
	t_node	*temp;

	temp = (t_node *)malloc(sizeof(t_node));
	temp->data = data;
	temp->index = index;
	temp->pos = pos;
	temp->next = (*head);
	*head = temp;
}
