/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_fc_interaction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:58:20 by aderugo           #+#    #+#             */
/*   Updated: 2023/04/04 22:08:17 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fc_check(char *str, char *string, t_data *data)
{
	if (!ft_strcmp(string, "F") || !ft_strcmp(string, "C"))
	{
		if (!ft_strcmp(string, "C"))
			data->main_map.text.the_color.c = get_fc_color(str, data);
		else
			data->main_map.text.the_color.f = get_fc_color(str, data);
	}
	else
		error("Error occured! Please check again!");
}

void	texture_check(char *string, char *str, t_data *data)
{
	if (!ft_strcmp(string, "NO"))
		if (!get_texture_image(str, data, &data->main_map.text.no))
			error("Invalid NO path!");
	if (!ft_strcmp(string, "SO"))
		if (!get_texture_image(str, data, &data->main_map.text.so))
			error("Invalid SO path!");
	if (!ft_strcmp(string, "WE"))
		if (!get_texture_image(str, data, &data->main_map.text.we))
			error("Invalid WE path!");
	if (!ft_strcmp(string, "EA"))
		if (!get_texture_image(str, data, &data->main_map.text.ea))
			error("Invalid EA path!");
}

char	*get_str(char *str)
{
	char	*string;
	int		i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	string = NULL;
	if (str[0] == 'N' && str[1] == 'O' && (str[2] == ' ' || str[2] == '\t'))
		string = ft_strdup("NO");
	else if (str[0] == 'S' && str[1] == 'O' && (str[2] == ' '
			|| str[2] == '\t'))
		string = ft_strdup("SO");
	else if (str[0] == 'W' && str[1] == 'E' && (str[2] == ' '
			|| str[2] == '\t'))
		string = ft_strdup("WE");
	else if (str[0] == 'E' && str[1] == 'A' && (str[2] == ' '
			|| str[2] == '\t'))
		string = ft_strdup("EA");
	else if (str[0] == 'F' && (str[1] == ' ' || str[1] == '\t'))
		string = ft_strdup("F");
	else if (str[0] == 'C' && (str[1] == ' ' || str[1] == '\t'))
		string = ft_strdup("C");
	else
		error("Error occured! Please check again!");
	return (string);
}

void	texture_fc_check(char *str, t_data *data)
{
	char	*string;

	string = get_str(str);
	if (ft_strlen(str) > ft_strlen(string) + 1)
		str += ft_strlen(string);
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if (!ft_strcmp(string, "NO") || !ft_strcmp(string, "SO")
		|| !ft_strcmp(string, "WE") || !ft_strcmp(string, "EA"))
		texture_check(string, str, data);
	else
		fc_check(str, string, data);
	free(string);
}

void	texture_fc_interaction(char **map, t_data *data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	data->count = 0;
	while (map[i] && j < 6)
	{
		if (map[i] && map[i][0] != '\n')
		{
			str = ft_strtrim(map[i], "' ''\t''\n");
			if (*str)
			{
				if (*str == 'F')
					data->count += 1;
				texture_fc_check(str, data);
				j++;
			}
			free(str);
		}
		i++;
	}
	if (data->count != 1)
		error("Error occured! Please check again!");
}
