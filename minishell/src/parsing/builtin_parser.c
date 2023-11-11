/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 02:25:11 by numussan          #+#    #+#             */
/*   Updated: 2023/01/21 20:03:00 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	parse_export_key(char *s)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(s);
	if (s[len - 1] == '+')
		len--;
	if (ft_isalpha(s[i++]) == 0)
		return (1);
	while (i < len)
	{
		if (ft_isalnum(s[i]) != 0)
			i++;
		else if (s[i] == '_')
			i++;
		else
			return (1);
	}
	return (0);
}

//checks validity of export 
int	parse_export(t_env *export_d, t_env **env_list)
{
	t_env	*temp;

	temp = export_d;
	while (temp != NULL)
	{
		if (parse_export_key(temp->key) == 1)
		{
			if (temp->val == NULL)
				printf("minishell: export:  '%s' not a valid identifier\n",
					temp->key);
			else
				printf("minishell: export:  '%s=%s' not a valid identifier\n",
					temp->key, temp->val);
		}
		else
			do_export(temp, env_list);
		temp = temp->next;
	}
	return (0);
}

void	get_push_export_d(char	*s, t_env	**export_d)
{
	char	*equal;
	char	*key;

	equal = ft_strchr(s, '=');
	if (equal == NULL)
		push(export_d, s, NULL);
	else
	{
		key = ft_substr(s, 0, ft_strlen(s) - ft_strlen(equal));
		push(export_d, key, &equal[1]);
		free(key);
	}
}
