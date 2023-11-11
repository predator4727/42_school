/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 02:01:15 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/04 22:11:12 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	img_init(t_data *data)
{
	t_img	img;

	img.ptr = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.ptr, &img.bit_per_pixel, &img.line_length,
			&img.endian);
	img.c_clr = data->main_map.text.the_color.c;
	img.f_clr = data->main_map.text.the_color.f;
	return (img);
}

void	game_init(t_data	*data)
{	
	float	ang;
	int		i;

	i = 0;
	data->player.x_slid = 0;
	data->player.y_slid = 0;
	if (data->player.type == 'W')
		ang = 180.1;
	else if (data->player.type == 'N')
		ang = -90.1;
	else if (data->player.type == 'S')
		ang = 90.1;
	else
		ang = 0.1;
	data->ch = 1;
	ang_update(&data->player.ang, ang);
	player_update(&data->player, &data->player.ang.value, data->main_map.map);
	data->main_map.text.colors = data->main_map.text.no.colors;
	while (data->main_map.map && data->main_map.map[i])
	{
		if (data->main_map.x_len < ft_strlen(data->main_map.map[i]))
			data->main_map.x_len = ft_strlen(data->main_map.map[i]);
		i++;
	}
	data->main_map.y_len = i;
}
