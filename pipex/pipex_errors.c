/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:01:40 by aderugo           #+#    #+#             */
/*   Updated: 2022/06/29 15:02:48 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_pipe(int *end)
{
	perror("Problems with pipe\n");
	close(end[0]);
	close(end[1]);
	exit(1);
}

void	error_pid(int *end)
{
	perror("Problems with PID\n");
	close(end[0]);
	close(end[1]);
	exit(1);
}

void	error_file(int file, int *end)
{
	perror("No such file or directory\n");
	close(file);
	close(end[0]);
	close(end[1]);
	exit(1);
}

void	error_path(char *path, int end)
{
	free(path);
	close(end);
	perror("command not found\n");
	exit(127);
}

void	error_execve(char *path, int end)
{
	free(path);
	close(end);
	perror("command not found\n");
	exit(127);
}
