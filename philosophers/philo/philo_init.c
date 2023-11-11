/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:39:43 by aderugo           #+#    #+#             */
/*   Updated: 2023/01/21 21:47:33 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_init_continue(t_dining *dining)
{
	int	i;

	i = 0;
	while (i < dining->nb_philo)
	{
		if (pthread_mutex_init(&dining->fork[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	ft_philo_init(t_dining *dining)
{
	int	i;
	int	temp;

	i = 0;
	while (i < dining->nb_philo)
	{
		dining->philo[i].id_philo = i + 1;
		dining->philo[i].count_eat = 0;
		dining->philo[i].left_fork = i;
		if (i < dining->nb_philo - 1)
			dining->philo[i].right_fork = i + 1;
		else
			dining->philo[i].right_fork = 0;
		if (i % 2 == 1)
		{
			temp = dining->philo[i].left_fork;
			dining->philo[i].left_fork = dining->philo[i].right_fork;
			dining->philo[i].right_fork = temp;
		}
		dining->philo[i].last_eat = 0;
		dining->philo[i].dining = dining;
		i++;
	}
	ft_philo_init_continue(dining);
	return (0);
}

t_dining	*ft_dining_init(int ac, char **s)
{
	t_dining	*dining;

	dining = malloc(sizeof(t_dining));
	if (!dining)
		return (NULL);
	dining->nb_philo = ft_atoi(s[1]);
	dining->tt_die = ft_atoi(s[2]);
	dining->tt_eat = ft_atoi(s[3]);
	dining->tt_sleep = ft_atoi(s[4]);
	dining->count_of_lunch = 0;
	if (ac == 6)
		dining->count_of_lunch = ft_atoi(s[5]);
	dining->death = 0;
	dining->time_start = 0;
	dining->thread = NULL;
	dining->fork = NULL;
	pthread_mutex_init(&dining->printer, NULL);
	pthread_mutex_init(&dining->c_eat, NULL);
	pthread_mutex_init(&dining->mutex_death, NULL);
	pthread_mutex_init(&dining->mut_last, NULL);
	return (dining);
}
