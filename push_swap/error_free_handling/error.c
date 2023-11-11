/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:15:22 by aderugo           #+#    #+#             */
/*   Updated: 2022/09/04 06:11:40 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	error_2(char *str, char **final_argv)
{
	free(str);
	free(final_argv);
	ft_printf("Error\n");
	exit(1);
}

void	free_error_complex(int *arr, char **final_argv, int index)
{
	free_complex_2(arr, final_argv, index);
	error();
}
