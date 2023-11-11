/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:24:16 by aderugo           #+#    #+#             */
/*   Updated: 2022/08/29 19:01:35 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sort(t_node **head)
{
	t_node	*temp;

	temp = *head;
	while (temp->next != NULL)
	{
		if (temp->data >= temp->next->data)
			return (-1);
		temp = temp->next;
	}
	return (0);
}
