/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_parent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:47:45 by aderugo           #+#    #+#             */
/*   Updated: 2023/01/21 22:47:18 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//checks if exit arguments r numeric
int	exit_check_arg(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_exit(t_cmd *cmd, t_env **env_list)
{
	int	n;

	if (cmd->args == NULL)
		return (0);
	if (ft_strcmp("exit", cmd->args[0]) == 0)
	{
		n = 0;
		if (ft_exit_helper(cmd) == 1)
			return (1);
		printf("exit\n");
		if (cmd->args[1] != NULL)
		{
			if (ft_strlen(cmd->args[1]) > 10
				|| exit_check_arg(cmd->args[1]))
				printf("minishell: exit: %s: numeric argument required\n",
					cmd->args[1]);
			else
				n = ft_atoi(cmd->args[1]);
		}
		free_cmd(&cmd);
		free_list(env_list);
		exit(n);
	}
	return (0);
}

int	ft_unset(t_cmd *cmd, t_env **env_list)
{
	t_env	*temp;
	int		i;

	i = 1;
	while (i < cmd->arg_c)
	{
		temp = *env_list;
		if (ft_strcmp(temp->key, cmd->args[i]) == 0)
			delete_head(env_list);
		temp = find_node_by_key_del(*env_list, cmd->args[i]);
		if (temp != NULL)
			delete_node(temp);
		i++;
	}
	g_global.signal = 0;
	return (1);
}

void	ft_cd_helper(t_env **env_list, t_env *home)
{
	t_env	*temp;
	t_env	*old_temp;
	char	*s;

	temp = find_node_by_key(*env_list, "PWD");
	old_temp = find_node_by_key(*env_list, "OLDPWD");
	s = getcwd(NULL, 0);
	if (temp->val == NULL || s == NULL)
	{
		if (s)
			free(s);
		temp->val = ft_strdup(home->val);
		old_temp->val = ft_strdup(home->val);
		return ;
	}
	if (s)
		free(s);
	free(old_temp->val);
	old_temp->val = ft_strdup(temp->val);
	free(temp->val);
	temp->val = getcwd(NULL, 0);
}

int	ft_cd(t_cmd *cmd, t_env **env_list)
{
	t_env	*home;
	int		ret;

	home = find_node_by_key(*env_list, "HOME");
	if (find_node_by_key(*env_list, "PWD") == NULL
		|| find_node_by_key(*env_list, "OLDPWD") == NULL || home == NULL)
		return (1);
	if (cmd->arg_c == 1 || ft_strcmp(cmd->args[1], "~") == 0)
	{
		chdir(home->val);
		ft_cd_helper(env_list, home);
		g_global.signal = 0;
		return (1);
	}
	ret = chdir(cmd->args[1]);
	if (ft_cd_error(cmd, env_list, ret) == 1)
		return (1);
	ft_cd_helper(env_list, home);
	g_global.signal = 0;
	return (1);
}
