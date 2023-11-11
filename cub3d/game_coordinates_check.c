/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_coordinates_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:00:38 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/04 22:13:45 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_in_map(t_map map, float x, float y)
{
	if ((int)y < 0 || y >= map.y_len * UNIT || x < 0
		|| x >= (ft_strlen(map.map[(int)(y / UNIT)]) * UNIT))
		return (0);
	return (1);
}

int	is_in_win(float x, float y)
{
	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT - 1)
		return (0);
	return (1);
}

int	is_a_wall(t_map main_map, float x, float y)
{
	char	**map;

	map = main_map.map;
	if (is_in_map(main_map, x, y)
		&& map[(int)(y / UNIT)][(int)(x / UNIT)] == '1')
	{
		return (1);
	}
	return (0);
}
