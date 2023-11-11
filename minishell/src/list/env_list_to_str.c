/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 02:25:11 by numussan          #+#    #+#             */
/*   Updated: 2023/01/23 13:45:24 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_env(t_env *env)
{
	t_env	*temp;
	int		count;

	count = 0;
	temp = env;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

char	*ft_str(char *key, char *val)
{
	char	*str;
	char	*str_eq;

	if (val == NULL)
		str = ft_strjoin(key, "=");
	else
	{
		str_eq = ft_strjoin(key, "=");
		str = ft_strjoin(str_eq, val);
		free(str_eq);
	}
	return (str);
}

char	**env_list_to_string(t_env *env)
{
	char	**env_s;
	t_env	*temp;
	int		i;

	i = 0;
	temp = env;
	env_s = malloc(sizeof(char *) * (count_env(env) + 1));
	while (temp != NULL)
	{
		env_s[i] = ft_str(temp->key, temp->val);
		temp = temp->next;
		i++;
	}
	env_s[i] = NULL;
	return (env_s);
}
