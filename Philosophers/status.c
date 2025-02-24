/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:14:07 by hdemirel          #+#    #+#             */
/*   Updated: 2024/04/30 12:34:03 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_p_eat(t_philo *philo)
{
	if (ft_check_death(philo))
		return ;
	pthread_mutex_lock(philo->left_fork);
	ft_p_print(philo, "has taken a fork", 0);
	pthread_mutex_lock(philo->right_fork);
	if (ft_check_death(philo))
		return ;
	ft_p_print(philo, "has taken a fork ", 0);
	pthread_mutex_lock(philo->death);
	philo->total_eaten++;
	pthread_mutex_unlock(philo->death);
	ft_p_print(philo, "is eating", 0);
	ft_p_wait_time(philo, philo->time_to_eat);
	pthread_mutex_lock(philo->death);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(philo->death);
	if (ft_check_death(philo))
		return ;
}

void	ft_p_sleep(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (ft_check_death(philo))
		return ;
	ft_p_print(philo, "is sleeping", 0);
	ft_p_wait_time(philo, philo->time_to_sleep);
}

void	ft_p_think(t_philo *philo)
{
	if (ft_check_death(philo))
		return ;
	ft_p_print(philo, "is thinking", 0);
}

void	ft_p_print(t_philo *philo, char *status, int kill)
{
	pthread_mutex_lock(philo->death);
	if (!*philo->check_dead)
	{
		printf ("%llu %d %s\n", (ft_get_time() - philo->start_time), \
		philo->id + 1, status);
		if (kill)
			*philo->check_dead = 1;
	}
	pthread_mutex_unlock(philo->death);
	ft_check_death(philo);
}

int	ft_p_wait_time(t_philo *philo, t_time wait_time)
{
	t_time	time;

	time = ft_get_time();
	while (ft_get_time() - time < wait_time)
	{
		if (ft_check_death(philo))
			return (1);
		usleep(10);
	}
	return (0);
}
