/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 01:27:14 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/04 22:35:46 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	basic_checks(int num_arg, char *path, t_data *data)
{
	check_num_arg(num_arg);
	check_file(path);
	check_fd(path, data);
}

void	check_num_arg(int num_arg)
{
	if (num_arg != 2)
		error("Wrong number of arguments!");
}

void	check_file(char *path)
{
	int	i;

	i = ft_strlen(path) - 4;
	if (path[i] != '.' && path[i + 1] != 'c' && \
				path[i + 2] != 'u' && path[i + 3] != 'b')
		error("Wrong file extension!!!");
}

void	check_fd(char *path, t_data *data)
{
	int	fd;

	fd = open(path, O_RDWR);
	if (fd < 0)
		error("<<<<< ERROR!!! >>>>>");
	data->fd = fd;
}
