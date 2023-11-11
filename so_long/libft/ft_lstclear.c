/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:15:45 by aderugo           #+#    #+#             */
/*   Updated: 2022/02/10 15:26:42 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;

	if (!del || !lst)
		return ;
	if (lst)
	{
		while (*lst != NULL)
		{
			next_node = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = next_node;
		}
	}
}
