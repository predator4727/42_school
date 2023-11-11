/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:02:37 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/04 22:13:29 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (is_in_win(x, y))
	{
		pixel = img->addr + (y * img->line_length + x
				* (img->bit_per_pixel / 8));
		*(int *)pixel = color;
	}
}

void	draw_wall(t_img *img, int index, t_ray ray, t_texture text)
{
	int		start;
	int		color;

	start = 0;
	ray.wall_start = (WIN_HEIGHT / 2) - (ray.wall_height / 2);
	ray.wall_end = (WIN_HEIGHT / 2) + (ray.wall_height / 2);
	if (ray.wall_end > WIN_HEIGHT)
		ray.wall_end = WIN_HEIGHT;
	while (start < ray.wall_start)
	{
		my_pixel_put(img, index, start, img->c_clr);
		start++;
	}
	while (start <= ray.wall_end)
	{
		color = text.colors[ray.color_index][((start - ray.wall_start)
				* text.img.y) / ray.wall_height];
		my_pixel_put(img, index, start, color);
		start++;
	}
	while (start <= WIN_HEIGHT)
	{
		my_pixel_put(img, index, start, img->f_clr);
		start++;
	}
}
