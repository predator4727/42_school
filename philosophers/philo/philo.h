/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:36:07 by numussan          #+#    #+#             */
/*   Updated: 2023/01/21 16:29:17 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_philo
{
	int				id_philo;
	int				count_eat;
	int				left_fork;
	int				right_fork;
	long long		time_start;
	long long		last_eat;
	struct s_dining	*dining;
}				t_philo;

typedef struct s_dining
{
	int				nb_philo;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				count_of_lunch;
	int				death;
	long long		time_start;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	printer;
	pthread_mutex_t	c_eat;
	pthread_mutex_t	mutex_death;
	pthread_mutex_t	mut_last;
	t_philo			*philo;
}				t_dining;

t_dining	*ft_dining_init(int ac, char **av);
int			ft_philo_init(t_dining *dining);
int			ft_start(t_dining *dining);
void		*ft_philo_start(void *tmp);
long		ft_atoi(char *s);
int			ft_free_dining(t_dining *dining);
// int			ft_free_dining_2(t_dining *dining);
int			ft_dining_malloc(t_dining *dining);
long		ft_time(void);
void		ft_usleep(long time);
void		ft_print(t_dining *dining, t_philo *philo, char *str);
int			ft_eat(t_dining *dining, t_philo *philo);
void		ft_sleep(t_dining *dining, t_philo *philo);
void		ft_think(t_dining *dining, t_philo *philo);
void		*ft_check_death(void *tmp);
int			ft_check_time_die(t_dining *dining, t_philo *philo, int i);
void		ft_mutex_destroy(t_dining *dining);
int			check_dining(int ac, t_dining *dining);

#endif
