/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 02:25:11 by numussan          #+#    #+#             */
/*   Updated: 2023/01/23 13:44:47 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	p_tokens(t_tokens *tokens)
{
	int	i;

	i = 0;
	printf("\n===================================\n");
	printf("tokens output\n");
	while (tokens->args[i] != NULL)
	{
		printf("[%s]  ", tokens->args[i]);
		i++;
	}
	printf("\ntoken_count: %d\n", tokens->arg_c);
	printf("===================================\n");
}

void	p_dp_arg(char **args)
{
	int	i;

	i = 0;
	if (args == NULL)
		printf("NULL");
	else
	{
		while (args[i] != NULL)
		{
			printf("[%s] ", args[i]);
			i++;
		}	
	}
}

void	p_inout(t_rdr *rdr)
{
	t_rdr	*temp;

	temp = rdr;
	if (temp == NULL)
	{
		printf("	NO REDIRECIONS\n\n");
		return ;
	}
	while (temp != NULL)
	{
		printf("	FILE: %s\n", temp->file);
		printf("	TYPE: %d\n", temp->type);
		printf("	RDR ARGS: ");
		p_dp_arg(temp->args);
		printf("\n	------------\n");
		temp = temp->next;
	}
	printf("\n\n");
}

void	p_cmd(t_cmd *cmd)
{
	t_cmd	*temp;

	temp = cmd;
	printf("===========cmd struct output=============\n");
	while (temp != NULL)
	{
		printf("\nARGS: ");
		p_dp_arg(temp->args);
		printf("\n");
		printf("ARGC: %d\n\n", temp->arg_c);
		printf("	INPUT REDIRECTIONS\n--------------------------------\n");
		p_inout(temp->input);
		printf("	OUTPUT REDIRECTIONS\n--------------------------------\n");
		p_inout(temp->output);
		temp = temp->next;
		if (temp != NULL)
			printf("\n=====================================\n");
	}
	printf("===================================\n\n");
}
