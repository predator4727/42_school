/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_interaction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:56:49 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/04 22:10:37 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isplayer(int c)
{
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
		return (1);
	return (0);
}

void	player_markup(char **map, int i, int j, t_data *data)
{
	if (ft_isplayer(map[i][j]))
	{
		data->player.x = (j + 0.5) * UNIT;
		data->player.y = (i + 0.5) * UNIT;
		data->player.type = map[i][j];
		map[i][j] = '0';
	}
}

void	check_map_elements(char **map, int i, int j, int *count)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	if (!check_map_symbols(map[i][j]))
		error("Found another character in the map!");
	check_for_player(map[i][j], count);
	basic_map_integrity_check(map, i, j, len);
	if ((map[i][j] == '0' || ft_isplayer(map[i][j])))
	{
		check_for_end(map, i, j);
		check_for_space(map, i, j);
	}
}

char	**get_map(char **file)
{
	t_norm	norm;

	norm.i = 0;
	norm.j = 0;
	while (file[norm.i])
		norm.i++;
	norm.map = (char **) malloc(sizeof(char *) * norm.i + 1);
	norm.i = 0;
	while (file[norm.i] && norm.j < 6)
	{
		norm.tmp = ft_strtrim(file[norm.i], "'''\t''\n'");
		if (norm.tmp && norm.tmp[0] != '\n'
			&& norm.tmp[0] != ' ' && norm.tmp[0] != '\t' && norm.tmp[0])
			norm.j++;
		norm.i++;
		free(norm.tmp);
	}
	norm.j = 0;
	while (file[norm.i] && (file[norm.i][0] == '\n' || file[norm.i][0] == '\t'))
		norm.i++;
	while (file[norm.i])
		norm.map[norm.j++] = ft_strdup(file[norm.i++]);
	norm.map[norm.j] = NULL;
	free_array(file);
	return (norm.map);
}

void	map_interaction(char **map, t_data *data)
{
	int	i;
	int	j;
	int	count;

	data->main_map.map = get_map(data->main_map.map);
	map = data->main_map.map;
	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '\n')
				check_map_elements(map, i, j, &count);
			player_markup(map, i, j, data);
			j++;
		}
		i++;
	}
	if (count != 1)
		error("One player needed in the map!");
}
