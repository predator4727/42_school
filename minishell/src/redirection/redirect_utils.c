/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:47:45 by aderugo           #+#    #+#             */
/*   Updated: 2023/01/21 22:46:33 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	arr_size(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return (i);
	while (arr[i] != NULL)
		i++;
	return (i);
}

//if we have 'ls < a -l'
//t_rdr->args will have the '-l'
//so we need to update the command struct args
//with the arg from t_rdr
//so here we re allocate for the new args we will add
//and io_args will contain both from t_rdr and t_cmd
void	update_io_args(t_cmd *cmd, t_rdr *file)
{
	char	**io_args;
	int		i;
	int		j;

	if (file->args == NULL)
		return ;
	io_args = NULL;
	i = 0;
	j = 0;
	io_args = malloc(sizeof(char *)
			* (arr_size(cmd->args) + arr_size(file->args) + 1));
	while (cmd->args[i] != NULL)
	{
		io_args[i] = ft_strdup(cmd->args[i]);
		i++;
	}
	while (file->args[j] != NULL)
	{
		io_args[i] = ft_strdup(file->args[j++]);
		i++;
	}
	io_args[i] = NULL;
	cmd->arg_c = i;
	free_doublptr(cmd->args);
	cmd->args = io_args;
}
