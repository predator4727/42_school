/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredog_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:47:45 by aderugo           #+#    #+#             */
/*   Updated: 2023/01/21 23:06:00 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//check the whole line if 'x << a| x<< a  '
//2
int	cmdline_heredogs_count(t_cmd *cmd)
{
	t_cmd	*curr_cmd;
	t_rdr	*file;
	int		count;

	count = 0;
	curr_cmd = cmd;
	file = cmd->input;
	while (curr_cmd != NULL)
	{
		if (curr_cmd->input)
		{
			file = curr_cmd->input;
			while (file)
			{
				if (file->type == HEREDOC)
				{
					count++;
					break ;
				}
				file = file->next;
			}
		}
		curr_cmd = curr_cmd->next;
	}
	return (count);
}

// "[ls << a << b << c] | cd << a"  
// we take one command at time and count how many heredoc there is
//in this case there is 3
int	heredogs_count(t_cmd *cmd)
{
	int		count;
	t_rdr	*temp;

	count = 0;
	temp = cmd->input;
	if (temp == NULL)
		return (count);
	while (temp != NULL)
	{
		if (temp->type == HEREDOC)
			count++;
		temp = temp->next;
	}
	return (count);
}

t_cmd	*get_heredog_cmd(t_cmd *cmd)
{
	t_cmd	*curr_cmd;
	t_rdr	*file;

	curr_cmd = cmd;
	file = cmd->input;
	while (curr_cmd != NULL)
	{
		if (cmd->input)
		{
			file = curr_cmd->input;
			while (file)
			{
				if (file->type == HEREDOC)
					return (curr_cmd);
				file = file->next;
			}
		}
		curr_cmd = curr_cmd->next;
	}
	return (0);
}

int	check_heredog(t_rdr *file)
{
	while (file)
	{
		if (file->type == HEREDOC)
			return (1);
		file = file->next;
	}
	return (0);
}

char	*generate_filename(int rand)
{
	char	*n;
	char	*s;

	n = ft_itoa(rand);
	s = ft_strjoin("tmp", n);
	free(n);
	return (s);
}
