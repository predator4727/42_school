/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 02:25:11 by numussan          #+#    #+#             */
/*   Updated: 2023/01/21 22:48:23 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_doublptr(char **s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != NULL)
		free(s[i++]);
	free(s);
	s = NULL;
}

void	free_rdr(t_rdr **rdr)
{
	t_rdr	*temp;
	t_rdr	*del_node;

	temp = *rdr;
	while (temp != NULL)
	{
		if (temp->file != NULL)
			free (temp->file);
		free_doublptr(temp->args);
		del_node = temp;
		temp = temp->next;
		free(del_node);
	}
	free(temp);
	rdr = NULL;
}

void	free_cmd(t_cmd **head)
{
	t_cmd	*temp;
	t_cmd	*del_node;

	temp = *head;
	while (temp != NULL)
	{
		free_doublptr(temp->args);
		if (temp->input != NULL)
			free_rdr(&temp->input);
		if (temp->output != NULL)
			free_rdr(&temp->output);
		del_node = temp;
		temp = temp->next;
		free(del_node);
	}
	free(temp);
	*head = NULL;
}
