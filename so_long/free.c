/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 05:42:51 by aderugo           #+#    #+#             */
/*   Updated: 2022/07/17 06:10:09 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_1(t_game *game, char *str, char *temp)
{
	free(game);
	free(str);
	free(temp);
}

void	free_2(char *str, char *temp)
{
	free(str);
	free(temp);
}

void	free_3(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
}
