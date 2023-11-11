/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:15:33 by aderugo           #+#    #+#             */
/*   Updated: 2022/08/29 22:16:16 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reset_i(t_node **head)
{
	t_node	*temp;
	int		i;

	temp = *head;
	i = 1;
	while (temp != NULL)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
}
