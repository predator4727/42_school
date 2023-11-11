/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_fc_interaction_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:57:27 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/04 22:08:30 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	rgb_to_int(int r, int g, int b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}

unsigned int	get_fc_color(char *str, t_data *data)
{
	int		i;
	int		j;
	char	**rgb;

	i = 0;
	j = -1;
	rgb = ft_split(str, ',');
	while (rgb[i])
		i++;
	if (i != 3)
		error("Invalid color!");
	while (++j < 3)
	{
		if (ft_isdigit(rgb[j][0]) == 0)
			error("Invalid color!");
	}
	data->color.r = atoi(rgb[0]);
	data->color.g = atoi(rgb[1]);
	data->color.b = atoi(rgb[2]);
	if (data->color.r < 0 || data->color.r > 255 || data->color.g < 0
		|| data->color.g > 255 || data->color.b < 0 || data->color.b > 255)
		error("Invalid color!");
	data->color.clr = rgb_to_int(data->color.r, data->color.g, data->color.b);
	free_array(rgb);
	return (data->color.clr);
}

int	get_texture_color(t_texture text, int x, int y)
{
	char	*pixel;
	int		i;

	i = 0;
	if (x >= text.img.x || y >= text.img.y || x < 0 || y < 0)
		return (0);
	pixel = text.img.addr
		+ (y * text.img.line_length + x * (text.img.bit_per_pixel / 8));
	i = *(int *)pixel;
	return (i);
}

void	fill_texture_color(t_texture *text)
{
	int	x;
	int	y;

	text->colors = malloc(sizeof(int *) * (text->img.x + 1));
	x = 0;
	while (x < text->img.x)
	{
		y = 0;
		text->colors[x] = malloc(sizeof(int ) * (text->img.y + 1));
		while (y < text->img.y)
		{
			text->colors[x][y] = get_texture_color(*text, x, y);
			y++;
		}
		text->colors[x][y] = 0;
		x++;
	}
	text->colors[x] = NULL;
}

int	get_texture_image(char *path, t_data *data, t_texture *text)
{
	text->img.ptr = mlx_xpm_file_to_image(data->mlx, path,
			&text->img.x, &text->img.y);
	if (!text->img.ptr)
		return (0);
	text->img.addr = mlx_get_data_addr(text->img.ptr,
			&text->img.bit_per_pixel,
			&text->img.line_length, &text->img.endian);
	fill_texture_color(text);
	return (1);
}
