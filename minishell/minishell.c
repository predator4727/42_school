/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 02:25:11 by numussan          #+#    #+#             */
/*   Updated: 2023/01/22 22:25:29 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokens_init(t_tokens *tokens)
{
	tokens->arg_c = 0;
	tokens->args = NULL;
	tokens->cmdl = NULL;
	tokens->start = 0;
	tokens->end = 0;
}

//signals init
//and mute errors for argc argv
void	signals_env_init(int argc, char **argv)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	argc = 0;
	if (argv == NULL)
		argc++;
}

void	check_if_ctr_d(t_tokens *tokens, t_env *env_list)
{
	if (tokens->cmdl == NULL)
	{
		free_token(tokens);
		free_list(&env_list);
		exit(0);
	}
}

//main programm here 
void	shell_routine(t_env	*env_list)
{
	t_tokens	*tokens;
	t_cmd		*cmd;

	cmd = NULL;
	tokens = NULL;
	while (1)
	{
		g_global.rand = 0;
		tokens = malloc(sizeof(t_tokens));
		tokens_init(tokens);
		wait(0);
		tokens->cmdl = readline("minishell$ ");
		check_if_ctr_d(tokens, env_list);
		if (start_parsing(tokens, &env_list, &cmd) == 0)
		{
			try_execute(&cmd, &env_list);
			free_cmd(&cmd);
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	t_env		*env_list;

	g_global.signal = 0;
	env_list = NULL;
	rl_catch_signals = 0;
	signals_env_init(argc, argv);
	init_env_list(&env_list, env);
	increment_shlvl(&env_list);
	shell_routine(env_list);
	return (0);
}
