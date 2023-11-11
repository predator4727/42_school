/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 02:25:11 by numussan          #+#    #+#             */
/*   Updated: 2023/01/22 23:37:19 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	er_rdr_no_file(char *s)
{
	write(2, "minishell: ", 11);
	write(2, s, ft_strlen(s));
	write(2, ": No such file or directory\n", 28);
	return (-1);
}

void	er_ft_execs(char *s)
{
	write(2, "minishell: ", 11);
	write(2, s, ft_strlen(s));
	write(2, ": command not found\n", 20);
}

int	is_all_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (is_separator(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

//checking input validity
int	start_parsing_err(t_tokens *tokens)
{
	if (is_all_spaces(tokens->cmdl) == 1)
	{
		free(tokens->cmdl);
		free(tokens);
		return (1);
	}
	add_history(tokens->cmdl);
	if (check_q(tokens->cmdl) == 1)
	{
		free(tokens->cmdl);
		free(tokens);
		return (1);
	}
	return (0);
}

void	create_pwd(t_env **env)
{
	t_env	*temp;
	t_env	*old_temp;
	t_env	*home;

	home = find_node_by_key(*env, "HOME");
	if (home == NULL)
		return ;
	temp = find_node_by_key(*env, "PWD");
	old_temp = find_node_by_key(*env, "OLDPWD");
	if (temp == NULL)
		push(env, "PWD", home->val);
	if (old_temp == NULL)
		push(env, "OLDPWD", home->val);
}
