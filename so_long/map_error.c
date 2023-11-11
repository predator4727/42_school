/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 03:00:53 by aderugo           #+#    #+#             */
/*   Updated: 2022/07/17 05:56:40 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	structure_map_error(t_game *game)
{
	free_3(game);
	perror("Assymetric_map_size\n");
	exit(1);
}

void	border_map_error(t_game *game)
{
	free_3(game);
	perror("Map_is_not_closed\n");
	exit(1);
}

void	components_map_error(t_game *game)
{
	free_3(game);
	perror("Wrong_component or Wrong_number_of_components\n");
	exit(1);
}

void	empty_line_map_error(t_game *game, char *str, char *temp)
{
	free_1(game, str, temp);
	perror("Map_is_not_valid\n");
	exit (1);
}
