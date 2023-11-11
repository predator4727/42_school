/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 02:25:11 by numussan          #+#    #+#             */
/*   Updated: 2023/01/23 13:45:21 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//duplicates env variables into list t_env
void	init_env_list(t_env **env_list, char **env)
{
	char	**env_split;
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		env_split = ft_split(env[i], '=');
		if (env_split[1] == NULL)
			push(env_list, env_split[0], NULL);
		else
			push(env_list, env_split[0], env_split[1]);
		i++;
		free_doublptr(env_split);
	}
}

//prints list of env varibales
void	print_env(t_env **head)
{
	t_env	*temp;

	temp = *head;
	while (temp != NULL)
	{
		if (temp->val != NULL)
			printf("%s=%s\n", temp->key, temp->val);
		temp = temp->next;
	}
}

//Returns node with provided key
//if there is no such key returns NULL
t_env	*find_node_by_key(t_env *lst, char *key)
{
	t_env	*node;

	if (lst == NULL)
		return (NULL);
	node = lst;
	while (node->next != NULL)
	{
		if (ft_strcmp(node->key, key) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

//return node thats points to the node with provided key
//needs to delete node if it not head
t_env	*find_node_by_key_del(t_env *lst, char *key)
{
	t_env	*node;

	if (lst == NULL)
		return (NULL);
	node = lst;
	while (node->next != NULL)
	{
		if (ft_strcmp(node->next->key, key) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}
