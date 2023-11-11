/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minihell_call.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:47:45 by aderugo           #+#    #+#             */
/*   Updated: 2023/01/21 22:47:29 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//call minishell inside of minishell
int	check_minishell_exec(t_cmd *cmd, t_env **env)
{
	int		pid;
	int		i;
	char	*str_cut;
	char	**env_s;

	i = 0;
	if (cmd->args[0][0] == '.' && cmd->args[0][1] == '/')
	{
		env_s = env_list_to_string(*env);
		str_cut = malloc(ft_strlen(cmd->args[0]) - 1);
		while (cmd->args[0][i + 2] != '\0')
		{
			str_cut[i] = cmd->args[0][i + 2];
			i++;
		}
		str_cut[i] = '\0';
		pid = fork();
		if (pid == 0)
			execve(str_cut, env_s, env_s);
		wait(0);
		free(str_cut);
		free_doublptr(env_s);
		return (1);
	}
	return (0);
}

//increments shlvl, if its > 1000 resets 0
void	increment_shlvl(t_env **env)
{
	t_env	*shlvl;
	int		lvl;

	shlvl = find_node_by_key(*env, "SHLVL");
	if (shlvl == NULL)
	{
		push(env, "SHLVL", "1");
		return ;
	}
	lvl = ft_atoi(shlvl->val);
	lvl++;
	if (lvl < 0)
		lvl = 0;
	else if (lvl >= 1000)
		lvl = 1;
	free(shlvl->val);
	shlvl->val = ft_itoa(lvl);
}
