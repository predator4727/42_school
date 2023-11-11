/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:22:08 by aderugo           #+#    #+#             */
/*   Updated: 2022/07/17 05:54:37 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_structure(t_game *game)
{
	int		n;
	int		i;

	i = 0;
	n = 0;
	while (game->map[n] != NULL)
		n++;
	game->height_map = n;
	game->width_map = ft_strlen(game->map[0]);
	while (n > 0)
	{
		if (game->width_map != ft_strlen(game->map[i]))
			structure_map_error(game);
		n--;
		i++;
	}
}

void	check_borders(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (game->map[j][i] != '\0')
	{
		if (game->map[0][i] != '1' || game->map[game->height_map - 1][i] != '1')
			border_map_error(game);
		i++;
	}
	j = 0;
	while (game->map[j])
	{
		if (game->map[j][0] != '1' ||
				game->map[j][game->width_map - 1] != '1')
			border_map_error(game);
		j++;
	}
}

void	check_components(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	while (game->map[i])
	{
		k = 0;
		while (game->map[i][k])
		{
			if (game->map[i][k] != '1' && game->map[i][k] != '0' &&
					game->map[i][k] != 'C' && game->map[i][k] != 'E' &&
						game->map[i][k] != 'P')
				components_map_error(game);
			k++;
		}
		i++;
	}
}

void	count_components(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	while (game->map[i])
	{
		k = 0;
		while (game->map[i][k])
		{
			if (game->map[i][k] == 'E')
				game->exit++;
			else if (game->map[i][k] == 'C')
				game->col++;
			else if (game->map[i][k] == 'P')
				game->player++;
			k++;
		}
		i++;
	}
	if (game->exit == 0 || game->col == 0 || game->player != 1)
		components_map_error(game);
}

int	parsing(char *file, t_game *game)
{
	char	*str;
	char	*temp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	str = NULL;
	temp = get_next_line(fd);
	temp_check_1(temp, fd, game);
	while (temp != NULL)
	{
		str = ft_strjoin_gnl(str, temp);
		free(temp);
		temp = get_next_line(fd);
		temp_check_2(temp, fd, str, game);
	}
	if (!str)
		return (-1);
	if (str[ft_strlen(str) - 1] == '\n')
		empty_line_map_error(game, str, temp);
	game->map = ft_split(str, '\n');
	free_2(str, temp);
	return (fd);
	close(fd);
}
