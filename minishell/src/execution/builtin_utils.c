/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:47:45 by aderugo           #+#    #+#             */
/*   Updated: 2023/01/21 22:47:12 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//trying to execute parent builtints 
int	try_parent_builtins(t_cmd *cmd, t_env **env)
{
	if (cmd->args != NULL)
	{
		if (ft_strcmp("exit", cmd->args[0]) == 0)
			return (ft_exit(cmd, env));
		if (ft_strcmp("cd", cmd->args[0]) == 0)
			return (ft_cd(cmd, env));
		else if (ft_strcmp("unset", cmd->args[0]) == 0)
			return (ft_unset(cmd, env));
		else if (ft_strcmp("export", cmd->args[0]) == 0)
			return (ft_export(cmd, env));
	}
	return (0);
}

//trying to execute child builtins
int	try_child_builtins(t_cmd *cmd, t_env **env)
{
	if (cmd->args != NULL)
	{
		if (ft_strcmp("export", cmd->args[0]) == 0)
			return (print_env_export(env));
		if (ft_strcmp("pwd", cmd->args[0]) == 0)
			return (ft_pwd());
		if (ft_strcmp("echo", cmd->args[0]) == 0)
			return (ft_echo(cmd));
		if (ft_strcmp("env", cmd->args[0]) == 0)
			return (ft_env(env));
	}
	return (0);
}

int	ft_cd_error(t_cmd *cmd, t_env **env_list, int ret)
{
	char	*s;
	t_env	*home;

	s = getcwd(NULL, 0);
	home = find_node_by_key(*env_list, "HOME");
	if (s == NULL)
		chdir(home->val);
	if (s)
		free(s);
	if (ret < 0)
	{
		write(2, "cd: no such file or directory: ", 31);
		write(2, cmd->args[1], ft_strlen(cmd->args[1]));
		write(2, "\n", 1);
		g_global.signal = 1;
		return (1);
	}
	return (0);
}

int	ft_exit_helper(t_cmd *cmd)
{
	if (cmd->arg_c > 2)
	{
		printf("minishell:  exit: too many arguments\n");
		return (1);
	}
	return (0);
}
