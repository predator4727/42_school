/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_interaction_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:52:19 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/04 22:17:48 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_for_end(char **map, int i, int j)
{
	if (map[i][j - 1] == '\0' || map[i][j + 1] == '\0'
		|| map[i - 1][j] == '\0' || map[i + 1][j] == '\0' || i == 0 || j == 0)
		error("Map isn't surrounded by 1's!");
}

void	check_for_space(char **map, int i, int j)
{
	if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || map[i - 1][j] == ' '
		|| map[i + 1][j] == ' ' || i == 0 || j == 0)
		error("Map isn't surrounded by 1's!");
}

void	basic_map_integrity_check(char **map, int i, int j, int len)
{
	if (map[i][j] == '\t')
		error("Found tab in the map");
	if ((map[i][j] == '0' || ft_isplayer(map[i][j])) && (i == 0 || j == 0))
		error("Map isn't surrounded by 1's!");
	if ((map[i][j] == '0' || ft_isplayer(map[i][j]))
		&& (i == len - 1 || map[i][j + 1] == '\n'))
		error("Map isn't surrounded by 1's!");
}

int	check_for_player(char c, int *count)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		*count += 1;
	return (*count);
}

int	check_map_symbols(int c)
{
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S' || c == '1'
		|| c == '0' || c == ' ')
		return (1);
	return (0);
}
