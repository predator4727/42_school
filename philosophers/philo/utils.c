/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:12:06 by aderugo           #+#    #+#             */
/*   Updated: 2023/01/21 21:12:30 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_dining *dining, t_philo *philo, char *str)
{
	pthread_mutex_lock(&dining->mutex_death);
	if (dining->death)
	{
		pthread_mutex_unlock(&dining->mutex_death);
		return ;
	}
	printf("%lld %d %s\n", \
		ft_time() - philo->time_start, philo->id_philo, str);
	pthread_mutex_unlock(&dining->mutex_death);
}

long	ft_time(void)
{
	struct timeval	ct;
	long			res;

	gettimeofday(&ct, NULL);
	res = (ct.tv_sec * 1000) + (ct.tv_usec / 1000);
	return (res);
}

void	ft_usleep(long time)
{
	long	end;

	end = ft_time() + time;
	while (ft_time() < end)
		usleep(time);
}

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	else
		return (1);
}

long	ft_atoi(char *str)
{
	long	result;
	int		flag;

	result = 0;
	flag = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			flag = -1;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str++ - '0';
	}
	if (ft_isdigit(*str) == 0 && *str)
		return (-1);
	if (result > INT_MAX && flag == 1)
		return (-1);
	if (((result - 1) > INT_MAX) && flag == -1)
		return (-1);
	result *= flag;
	return (result);
}
