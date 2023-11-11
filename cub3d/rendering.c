/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:04:17 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/04 22:12:35 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	short_ray_cast(t_player player, t_map map, float ray_ang)
{
	t_ray	v_ray;
	t_ray	h_ray;

	h_ray = hor_ray_init(&player, ray_ang, map);
	v_ray = vert_ray_init(&player, ray_ang, map);
	if (h_ray.len > v_ray.len)
	{
		ray_add_wall_data(&v_ray, map);
		return (v_ray);
	}
	else
	{
		ray_add_wall_data(&h_ray, map);
		return (h_ray);
	}
}

t_ray	*rays_render(t_img *img, t_player player, t_map map)
{
	float	ray_ang;
	int		ray_index;
	float	s;
	t_ray	*rays;

	rays = malloc(sizeof(t_ray) * WIN_WIDTH);
	s = 60.0 / WIN_WIDTH;
	ray_index = 0;
	ray_ang = -30;
	while (ray_index < WIN_WIDTH)
	{
		rays[ray_index] = short_ray_cast(player, map, ray_ang);
		draw_wall(img, ray_index, rays[ray_index], rays[ray_index].text);
		ray_index ++;
		ray_ang += s;
	}
	return (rays);
}

int	rendering(t_data *data)
{
	t_img	img;
	t_ray	*rays;

	if (data->ch)
	{
		mlx_clear_window(data->mlx, data->win.ptr);
		img = img_init(data);
		rays = rays_render(&img, data->player, data->main_map);
		mlx_put_image_to_window(data->mlx, data->win.ptr, img.ptr, 0, 0);
		mlx_destroy_image(data->mlx, img.ptr);
		free(rays);
	}
	data->ch = 0;
	return (0);
}
