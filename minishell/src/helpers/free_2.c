/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 02:25:11 by numussan          #+#    #+#             */
/*   Updated: 2023/01/21 22:48:28 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//free parsing structure
void	free_token(t_tokens *t)
{
	if (t != NULL)
	{
		if (t->cmdl)
			free(t->cmdl);
		free(t);
	}
}

//free env list
void	free_list(t_env **list)
{
	t_env	*temp;

	temp = *list;
	while (temp != NULL)
	{
		delete_head(list);
		temp = *list;
	}
}

//free helper parsing sructure
void	free_parsing(t_parsing *prs)
{
	if (prs->og_token != NULL)
		free(prs->og_token);
	if (prs->token != NULL)
		free(prs->token);
	free_doublptr(prs->exp_name);
	free(prs);
	prs = NULL;
}

void	free_for_start_parsing(t_tokens *tokens)
{
	free_doublptr(tokens->args);
	free(tokens->cmdl);
	free(tokens);
}
