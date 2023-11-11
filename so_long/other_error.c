/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:21:07 by aderugo           #+#    #+#             */
/*   Updated: 2022/07/17 05:57:05 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing_error(t_game *game)
{
	free(game);
	perror("Parsing_error\n");
	exit (1);
}

void	file_error(t_game *game)
{
	free(game);
	perror("Wrong_file_extention\n");
	exit (1);
}

void	window_mlx_error(t_game *game)
{
	free_3(game);
	perror("Window_mlx_error\n");
	exit (1);
}

void	number_parametres_error(void)
{
	perror("Wrong_number_of_parametres\n");
	exit (1);
}
