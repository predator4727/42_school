/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:12:06 by aderugo           #+#    #+#             */
/*   Updated: 2023/01/22 13:21:11 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_time_die(t_dining *dining, t_philo *philo, int i)
{
	pthread_mutex_lock(&dining->mut_last);
	if (ft_time() - philo[i].last_eat > philo[i].dining->tt_die)
	{
		pthread_mutex_unlock(&dining->mut_last);
		pthread_mutex_lock(&dining->mutex_death);
		dining->death = 1;
		pthread_mutex_unlock(&dining->mutex_death);
		pthread_mutex_lock(&dining->printer);
		printf("%lld %d is died\n", \
			ft_time() - philo->time_start, philo->id_philo);
		pthread_mutex_unlock(&dining->printer);
		return (1);
	}
	pthread_mutex_unlock(&dining->mut_last);
	return (0);
}

void	*ft_check_death(void *tmp)
{
	t_dining	*dining;
	t_philo		*philo;
	int			i;

	dining = tmp;
	philo = dining->philo;
	while (1)
	{
		i = -1;
		while (++i < dining->nb_philo)
		{
			pthread_mutex_lock(&dining->c_eat);
			if (dining->count_of_lunch)
				if (philo->count_eat == dining->count_of_lunch)
					return (pthread_mutex_unlock(&dining->c_eat), NULL);
			pthread_mutex_unlock(&dining->c_eat);
			if (ft_check_time_die(dining, philo, i))
				return (NULL);
		}
	}
	return (NULL);
}

void	ft_think(t_dining *dining, t_philo *philo)
{
	pthread_mutex_lock(&dining->mutex_death);
	if (dining->death)
	{
		pthread_mutex_unlock(&dining->mutex_death);
		return ;
	}
	pthread_mutex_unlock(&dining->mutex_death);
	ft_print(dining, philo, "is thinking");
}

void	ft_sleep(t_dining *dining, t_philo *philo)
{
	pthread_mutex_lock(&dining->mutex_death);
	if (dining->death)
	{
		pthread_mutex_unlock(&dining->mutex_death);
		return ;
	}
	pthread_mutex_unlock(&dining->mutex_death);
	ft_print(dining, philo, "is sleeping");
	ft_usleep(philo->dining->tt_sleep);
}

int	ft_eat(t_dining *dining, t_philo *philo)
{
	pthread_mutex_lock(&dining->mutex_death);
	if (dining->death)
		return (pthread_mutex_unlock(&dining->mutex_death), 1);
	pthread_mutex_unlock(&dining->mutex_death);
	pthread_mutex_lock(&dining->fork[philo->left_fork]);
	ft_print(dining, philo, "has taken a fork");
	if (dining->nb_philo == 1)
		return (pthread_mutex_unlock(&dining->fork[philo->left_fork]), 1);
	pthread_mutex_lock(&dining->fork[philo->right_fork]);
	ft_print(dining, philo, "has taken a fork");
	ft_print(dining, philo, "is eating");
	pthread_mutex_lock(&dining->c_eat);
	philo->count_eat++;
	pthread_mutex_unlock(&dining->c_eat);
	pthread_mutex_lock(&dining->mut_last);
	philo->last_eat = ft_time();
	pthread_mutex_unlock(&dining->mut_last);
	ft_usleep(philo->dining->tt_eat);
	pthread_mutex_unlock(&dining->fork[philo->right_fork]);
	pthread_mutex_unlock(&dining->fork[philo->left_fork]);
	return (0);
}
