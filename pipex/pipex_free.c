/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_problems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:01:40 by aderugo           #+#    #+#             */
/*   Updated: 2022/06/27 17:05:12 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_free_1(char *path, char *path_command, char *all_paths)
{
	free(path);
	free(path_command);
	free(all_paths);
}

void	pipex_free_2(char **all_paths, char **command)
{
	int	i;

	free(all_paths);
	i = -1;
	while (command[++i])
		free(command[i]);
	free(command);
}
