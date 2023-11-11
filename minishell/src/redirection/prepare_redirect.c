/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:47:45 by aderugo           #+#    #+#             */
/*   Updated: 2023/01/21 22:46:27 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//preparing input files.
//file will be stored in cmd->input in out structure.
//if file is not empty we check type if REDL <, prepped_heredoc
//is a heredoc that we already opened files for with the input
//that we get in terminal.
void	prep_in_files(t_cmd *cmd)
{
	int		fd;
	t_rdr	*file;

	file = cmd->input;
	while (file != NULL)
	{
		if (file->type == REDL || file->type == PREPPED_HEREDOC)
			fd = (open(file->file, O_RDONLY));
		if (fd < 0)
			return ;
		if (file->args != NULL)
			update_io_args(cmd, file);
		file = file->next;
		close(fd);
	}
}

//
void	prep_out_files(t_cmd *cmd)
{
	int		fd;
	t_rdr	*file;

	file = cmd->output;
	while (file != NULL)
	{
		if (file->type == REDR)
			fd = (open(file->file, O_WRONLY | O_CREAT | O_TRUNC, 0666));
		else if (file->type == REDRR)
			fd = (open(file->file, O_WRONLY | O_APPEND | O_CREAT, 0666));
		if (fd < 0)
			return ;
		if (file->args != NULL)
			update_io_args(cmd, file);
		file = file->next;
		close(fd);
	}
}

//prepare files for heredoc so we can execute commands with input files
//preparing all <,> redirections. bcz we have to open all files before anything
void	prep_redirections(t_cmd *cmd, t_env **env)
{
	int	hd_c;

	hd_c = cmdline_heredogs_count(cmd);
	if (hd_c > 0)
		prep_heredogs(cmd, env);
	while (cmd)
	{
		if (cmd->input)
			prep_in_files(cmd);
		if (cmd->output)
			prep_out_files(cmd);
		cmd = cmd->next;
	}
}
