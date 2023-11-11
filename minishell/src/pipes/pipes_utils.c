/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:47:45 by aderugo           #+#    #+#             */
/*   Updated: 2023/01/21 23:05:47 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//close ALL pipes
void	ft_closer(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp->next != NULL)
	{
		if (tmp->fd[0])
			close(tmp->fd[0]);
		if (tmp->fd[1])
			close(tmp->fd[1]);
		tmp = tmp->next;
	}
}

void	close_all_pipes(t_cmd *cmd)
{
	t_cmd	*temp;

	temp = cmd;
	while (temp->prev != NULL)
	{
		temp = temp->prev;
		if (temp->fd[0])
			close(temp->fd[0]);
		if (temp->fd[1])
			close(temp->fd[1]);
	}
	temp = cmd;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->fd[0])
			close(temp->fd[0]);
		if (temp->fd[1])
			close(temp->fd[1]);
	}
}

//if first cmd
//if last cmd
//else is middle commands
//this function handles the piping and rediricting output
//into input of next commands.
//if last command, the output will be 1
//if first command, the the input will be 0.
void	ft_dup2(t_cmd *cmd, int *prev_fd)
{
	if (cmd->first_cmd == 1)
	{
		dup2(cmd->fd[1], 1);
		close(cmd->fd[0]);
		close(cmd->fd[1]);
	}
	else if (cmd->next == NULL)
	{
		dup2(prev_fd[0], 0);
		close(prev_fd[1]);
		close(prev_fd[0]);
	}
	else
	{
		dup2(prev_fd[0], 0);
		close(prev_fd[0]);
		close(prev_fd[1]);
		dup2(cmd->fd[1], 1);
		close(cmd->fd[1]);
		close(cmd->fd[0]);
	}
}

void	close_unused_fds(t_cmd *cmd, int counter)
{
	int		i;
	t_cmd	*temp;

	i = 0;
	temp = cmd;
	while (temp->next != NULL)
	{
		if (i != counter && i != counter - 1)
		{
			if (temp->fd[0])
			{
				close(temp->fd[0]);
				temp->fd[0] = 0;
			}
			if (temp->fd[1])
			{
				close(temp->fd[1]);
				temp->fd[1] = 0;
			}
		}
		temp = temp->next;
		i++;
	}
}
