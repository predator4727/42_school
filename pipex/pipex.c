/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:25:14 by aderugo           #+#    #+#             */
/*   Updated: 2022/06/30 17:10:50 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char	*argv, char **envp)
{
	char	*path;
	char	*path_command;
	char	**all_paths;
	char	**command;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	all_paths = ft_split(envp[i] + 5, ':');
	i = -1;
	command = ft_split(argv, ' ');
	while (all_paths[++i])
	{
		path_command = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(path_command, command[0]);
		if (access(path, X_OK) == 0)
			return (path);
		pipex_free_1(path, path_command, all_paths[i]);
	}
	pipex_free_2(all_paths, command);
	return (NULL);
}

void	child_process_1(int *end, char **argv, char **envp)
{
	int		file;
	char	*path;

	file = open(argv[1], O_RDONLY);
	if (file < 0)
		error_file(file, end);
	dup2(file, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(file);
	path = NULL;
	if (access(argv[2], X_OK) == 0)
		path = argv[2];
	else
	{
		path = get_path(argv[2], envp);
		if (!path)
			error_path(path, end[1]);
	}
	if (execve(path, ft_split(argv[2], ' '), envp) == -1)
		error_execve(path, end[1]);
}

void	child_process_2(int *end, char **argv, char **envp)
{
	int		file;
	char	*path;

	file = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (file < 0)
		error_file(file, end);
	dup2(file, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[1]);
	close(file);
	path = NULL;
	if (access(argv[3], X_OK) == 0)
		path = argv[3];
	else
	{
		path = get_path(argv[3], envp);
		if (!path)
			error_path(path, end[0]);
	}
	if (execve(path, ft_split(argv[3], ' '), envp) == -1)
		error_execve(path, end[0]);
}

int	pipex(char **argv, char **envp)
{
	pid_t	pid[2];
	int		end[2];
	int		status;
	int		i;

	i = -1;
	if (pipe(end) == -1)
		error_pipe(end);
	while (++i < 2)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			error_pid(end);
		if (i == 1)
			break ;
		if (pid[i] == 0)
			child_process_1(end, argv, envp);
	}
	if (pid[1] == 0)
		child_process_2(end, argv, envp);
	close(end[0]);
	close(end[1]);
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
	return (WEXITSTATUS(status));
}

int	main(int argc, char *argv[], char *envp[])
{
	int		exit_child;

	if (argc == 5)
	{
		args_check(argv[2]);
		args_check(argv[3]);
		exit_child = pipex(argv, envp);
	}
	else
	{
		perror("< file1 cmd1 | cmd2 > file2\n");
		exit(1);
	}
	return (exit_child);
}
