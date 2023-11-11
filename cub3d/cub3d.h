/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 01:21:55 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/04 22:21:45 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

# define SPEED 12
# define RO_SPEED 4
# define COL_SPEED 6
# define UNIT 50
# define WIN_HEIGHT 720
# define WIN_WIDTH 1280

typedef struct s_norm
{
	int		i;
	int		j;
	char	*tmp;
	char	**map;
}	t_norm;

typedef struct s_cords
{
	float	x;
	float	y;
}	t_cords;

typedef struct s_ang
{
	float	value;
	int		to_right;
	int		to_up;
	int		x_ofs;
	int		y_ofs;
}	t_ang;

typedef struct s_img
{
	char	*addr;
	void	*ptr;
	int		x;
	int		y;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
	int		c_clr;
	int		f_clr;
}	t_img;

typedef struct s_player
{
	float		x;
	float		y;
	float		dx;
	float		dy;
	int			can_move_f;
	int			can_move_b;
	int			x_slid;
	int			y_slid;
	char		type;
	t_ang		ang;
}	t_player;

typedef struct s_color
{
	unsigned int	c;
	unsigned int	f;
	int				r;
	int				g;
	int				b;
	int				clr;
}	t_color;

typedef struct s_texture
{
	int				**colors;
	t_img			img;
	t_color			the_color;
}	t_texture;

typedef struct s_textures
{
	int				**colors;
	t_img			img;
	t_texture		no;
	t_texture		so;
	t_texture		ea;
	t_texture		we;
	t_color			the_color;
}	t_textures;

typedef struct s_ray
{
	t_cords		start;
	t_cords		end;
	t_ang		ang;
	t_texture	text;
	float		len;
	float		ang_tg;
	float		dx;
	float		dy;
	float		ang_addj;
	float		step;
	float		x_step;
	float		y_step;
	int			wall_color;
	int			color_index;
	int			wall_start;
	int			wall_end;
	int			is_vert;
	int			wall_height;
}	t_ray;

typedef struct s_map
{
	char		**map;
	int			x_len;
	int			y_len;
	t_textures	text;
	t_player	player;
}	t_map;

typedef struct s_window
{
	void	*ptr;
	int		high;
	int		width;
}	t_window;

typedef struct s_data
{
	void		*mlx;
	int			fd;
	int			ch;
	int			count;
	t_img		img;
	t_map		main_map;
	t_color		color;
	t_window	win;
	t_player	player;
	t_textures	text;
	t_ang		ang;
}	t_data;

void			basic_checks(int num_arg, char *path, t_data *data);
void			check_num_arg(int num_arg);
void			check_file(char *path);
void			check_fd(char *path, t_data *data);
char			**read_file(t_data *data);
void			texture_fc_interaction(char **map, t_data *data);
char			*get_str(char *str);
int				get_texture_color(t_texture text, int x, int y);
int				get_texture_image(char *path, t_data *data, t_texture *text);
void			fill_texture_color(t_texture *text);
unsigned int	get_fc_color(char *str, t_data *data);
unsigned int	rgb_to_int(int r, int g, int b);
void			map_interaction(char **map, t_data *data);
char			**get_map(char **file);
int				check_map_symbols(int c);
void			check_for_end(char **map, int i, int j);
void			check_for_space(char **map, int i, int j);
int				check_for_player(char c, int *count);
void			basic_map_integrity_check(char **map, int i, int j, int len);
int				ft_isplayer(int c);
void			game_init(t_data *data);
int				key_hook(int keycode, t_data *data);
int				ft_exit(t_data *data);
int				rendering(t_data *data);
int				can_move_side(t_player *player, t_map map, int to_right);
int				is_a_wall(t_map main_map, float x, float y);
int				is_in_win(float x, float y);
int				is_in_map(t_map map, float x, float y);
void			ray_init(t_player *player, t_ray *ray, float ang);
void			add_collision_trans(t_player *player, char **map, int fact);
void			ang_update(t_ang *ang, float value);
void			my_pixel_put(t_img *img, int x, int y, int color);
void			player_update(t_player *player, float *ang, char **map);
void			ray_casting(t_ray *ray, t_map map);
void			ray_add_wall_data(t_ray *ray, t_map map);
void			draw_wall(t_img *img, int index, t_ray ray, t_texture text);
t_ray			*rays_render(t_img *img, t_player player, t_map map);
t_ray			vert_ray_init(t_player *player, float ang, t_map map);
t_ray			hor_ray_init(t_player *player, float ang, t_map map);
t_img			img_init(t_data *data);
void			error(char *str);
void			free_array(char **arr);

#endif