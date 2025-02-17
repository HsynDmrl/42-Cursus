/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:11:06 by hdemirel          #+#    #+#             */
/*   Updated: 2024/04/30 12:33:26 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef unsigned long long	t_time;

typedef struct s_philo
{
	int				id;
	int				must_eat;
	int				number_of_philo;
	int				total_eaten;
	int				*check_dead;
	t_time			time_to_die;
	t_time			time_to_eat;
	t_time			time_to_sleep;
	t_time			start_time;
	t_time			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*death;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

int		ft_args_check(int ac, char **av);
int		ft_check_death(t_philo *philo);
int		ft_p_wait_time(t_philo *philo, t_time wait_time);
t_time	ft_get_time(void);
long	ft_atol(const char *str);
void	ft_p_eat(t_philo *philo);
void	ft_p_sleep(t_philo *philo);
void	ft_p_think(t_philo *philo);
void	*ft_philo_check(void *args);
void	ft_args_init(t_philo *philo, int ac, char **av);
void	ft_create_threads(t_philo *philo);
void	ft_p_print(t_philo *philo, char *status, int kill);
void	ft_mutex_init(t_philo *philo, pthread_mutex_t *forks, \
			pthread_mutex_t *death);

#endif
