/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_cmd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 02:25:11 by numussan          #+#    #+#             */
/*   Updated: 2023/01/23 13:45:16 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	push_rdr_init_data(t_rdr *new_node, t_tokens *tokens)
{
	int	i;

	i = 0;
	if (tokens->end - ++tokens->start > 0)
	{
		i = 0;
		new_node->args = malloc(sizeof(char *)
				* (tokens->end - tokens->start + 1));
		while (tokens->start < tokens->end)
		{
			new_node->args[i++] = ft_strdup(tokens->args[tokens->start]);
			tokens->start++;
		}
		new_node->args[i] = NULL;
	}
}

void	push_cmd_init_data(t_cmd *new_node, t_tokens *tokens)
{
	int	i;

	i = 0;
	if (tokens->end - tokens->start != 0)
	{
		new_node->args = malloc(sizeof(char *)
				* (tokens->end - tokens->start + 1));
		while (tokens->start < tokens->end)
		{
			new_node->args[i++] = ft_strdup(tokens->args[tokens->start]);
			tokens->start++;
		}
		new_node->args[i] = NULL;
	}
	else
		new_node->args = NULL;
	new_node->arg_c = i;
}
