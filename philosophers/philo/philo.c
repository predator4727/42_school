/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:12:06 by aderugo           #+#    #+#             */
/*   Updated: 2023/01/21 21:57:53 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mutex_destroy(t_dining *dining)
{
	int	i;

	i = -1;
	while (++i < dining->nb_philo)
	{
		if (pthread_mutex_destroy(&dining->fork[i]))
			printf("ERROR destroy mutex %d!\n", i);
	}
	pthread_mutex_destroy(&dining->printer);
	pthread_mutex_destroy(&dining->c_eat);
	pthread_mutex_destroy(&dining->mutex_death);
	pthread_mutex_destroy(&dining->mut_last);
}

int	ft_free_dining(t_dining *dining)
{
	if (dining->philo)
		free(dining->philo);
	if (dining->fork)
		free(dining->fork);
	if (dining->thread)
		free(dining->thread);
	free(dining);
	return (1);
}

int	ft_dining_malloc(t_dining *dining)
{
	dining->philo = malloc(sizeof(t_philo) * dining->nb_philo);
	if (!dining->philo)
		return (1);
	dining->fork = malloc(sizeof(pthread_mutex_t) * dining->nb_philo);
	if (!dining->fork)
		return (1);
	dining->thread = malloc(sizeof(pthread_t) * dining->nb_philo);
	if (!dining->thread)
		return (1);
	return (0);
}

int	check_dining(int ac, t_dining *dining)
{
	if (dining->nb_philo < 0 || dining->tt_die < 0
		|| dining->tt_eat < 0 || dining->tt_sleep < 0)
		return (1);
	if (ac == 6)
		if (dining->count_of_lunch < 0)
			return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_dining	*dining;

	if (ac != 5 && ac != 6)
	{
		printf("wrong number of params\n");
		return (1);
	}
	dining = ft_dining_init(ac, av);
	if (!dining || check_dining(ac, dining))
	{
		free(dining);
		printf("wrong input\n");
		return (1);
	}
	if (ft_dining_malloc(dining) || ft_philo_init(dining))
	{
		printf("error\n");
		return (ft_free_dining(dining));
	}
	ft_start(dining);
	ft_mutex_destroy(dining);
	ft_free_dining(dining);
	return (0);
}
