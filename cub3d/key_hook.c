/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:03:16 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/04 22:12:21 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(t_data *data)
{
	(void) data;
	exit(0);
}

int	can_move_side(t_player *player, t_map map, int to_right)
{
	float	x;
	float	y;
	float	ang;

	ang = player->ang.value + 90;
	if (to_right)
		ang = player->ang.value - 90;
	x = player->x + cos(ang * (M_PI / 180)) * 20;
	y = player->y + sin(ang * (M_PI / 180)) * 20;
	if ((player->can_move_b || player->can_move_f)
		&& map.map[(int)y / UNIT][(int)x / UNIT] != '1')
	{
		player->x = x - cos(ang * (M_PI / 180)) * 15;
		player->y = y - sin(ang * (M_PI / 180)) * 15;
		return (1);
	}
	return (0);
}

void	f_move(t_data *data)
{
	if (!data->player.can_move_f)
		add_collision_trans(&data->player, data->main_map.map, 1);
	else
	{
		data->player.x_slid = 0;
		data->player.y_slid = 0;
		data->player.x += data->player.dx * SPEED;
		data->player.y += data->player.dy * SPEED;
	}
}

void	b_move(t_data *data)
{
	if (!data->player.can_move_b)
		add_collision_trans(&data->player, data->main_map.map, -1);
	else
	{
		data->player.x_slid = 0;
		data->player.y_slid = 0;
		data->player.x -= data->player.dx * SPEED;
		data->player.y -= data->player.dy * SPEED;
	}
}

int	key_hook(int keycode, t_data *data)
{
	char	**map;

	map = data->main_map.map;
	if (keycode == 123)
		data->player.ang.value -= RO_SPEED;
	if (keycode == 124)
		data->player.ang.value += RO_SPEED;
	player_update(&data->player, &data->player.ang.value, data->main_map.map);
	if ((keycode == 126 || keycode == 13))
		f_move(data);
	if ((keycode == 125 || keycode == 1))
		b_move(data);
	if (keycode == 2)
		can_move_side(&data->player, data->main_map, 0);
	if (keycode == 0)
		can_move_side(&data->player, data->main_map, 1);
	if (keycode == 53)
		ft_exit(data);
	data->ch = 1;
	return (0);
}
