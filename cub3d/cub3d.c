/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 01:12:55 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/04 22:06:31 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	error(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

char	**read_file(t_data *data)
{
	char	**line;
	int		i;

	line = (char **) malloc(sizeof(char *) * 100000);
	i = 0;
	line[i] = get_next_line(data->fd);
	if (!line[i])
		exit(-1);
	while (line[i++])
		line[i] = get_next_line(data->fd);
	close(data->fd);
	return (line);
}

int	main(int ac, char **av)
{
	t_data	data;

	basic_checks(ac, av[1], &data);
	data.mlx = mlx_init();
	data.main_map.map = read_file(&data);
	texture_fc_interaction(data.main_map.map, &data);
	map_interaction(data.main_map.map, &data);
	data.win.ptr = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	game_init(&data);
	mlx_hook(data.win.ptr, 02, 0, key_hook, &data);
	mlx_hook(data.win.ptr, 17, 0, ft_exit, &data);
	mlx_loop_hook(data.mlx, rendering, &data);
	mlx_loop(data.mlx);
}
