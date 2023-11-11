/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:12:06 by aderugo           #+#    #+#             */
/*   Updated: 2023/01/21 21:40:27 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_start_continue(t_dining *dining, t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&dining->mutex_death);
		if (dining->death)
			return (pthread_mutex_unlock(&dining->mutex_death), NULL);
		pthread_mutex_unlock(&dining->mutex_death);
		if (dining->count_of_lunch)
			if (philo->count_eat == dining->count_of_lunch)
				return (NULL);
		if (ft_eat(dining, philo))
			return (NULL);
		ft_sleep(dining, philo);
		ft_think(dining, philo);
	}
}

void	*ft_philo_start(void *tmp)
{
	t_philo		*philo;
	t_dining	*dining;

	philo = (t_philo *)tmp;
	dining = philo->dining;
	if (philo->id_philo % 2 == 0)
	{
		ft_print(dining, philo, "is thinking");
		usleep(philo->dining->tt_eat);
	}
	ft_philo_start_continue(dining, philo);
	return (NULL);
}

int	ft_start_continue(t_dining *dining)
{
	int			i;
	pthread_t	check;

	i = 0;
	while (i < dining->nb_philo)
	{
		pthread_create(&dining->thread[i], \
			NULL, &ft_philo_start, &dining->philo[i]);
		i++;
	}
	pthread_create(&check, NULL, &ft_check_death, dining);
	pthread_join(check, NULL);
	i = 0;
	while (i < dining->nb_philo)
	{
		pthread_join(dining->thread[i], NULL);
		i++;
	}
	return (0);
}

int	ft_start(t_dining *dining)
{
	int	i;

	i = 0;
	dining->time_start = ft_time();
	while (i < dining->nb_philo)
	{
		dining->philo[i].time_start = dining->time_start;
		dining->philo[i].last_eat = dining->time_start;
		i++;
	}
	return (ft_start_continue(dining));
}
