/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 06:43:26 by aderugo           #+#    #+#             */
/*   Updated: 2022/09/02 17:53:39 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_list(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		del_node(head);
		tmp = *head;
	}
}
