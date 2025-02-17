/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:44:16 by hdemirel          #+#    #+#             */
/*   Updated: 2024/04/30 12:34:22 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philo)
	{
		pthread_create(&philo[i].thread, NULL, &ft_philo_check, &philo[i]);
		i++;
		usleep(100);
	}
	if (ft_check_death(philo))
		return ;
	i = 0;
	while (i < philo->number_of_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

void	*ft_philo_check(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->number_of_philo == 1 && !ft_check_death(philo))
	{
		if (pthread_mutex_lock(philo->left_fork))
			return (NULL);
		ft_p_print(philo, " has taken a fork", 0);
		while (!ft_check_death(philo))
		{
		}
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		while (1)
		{
			if (ft_check_death(philo))
				break ;
			ft_p_eat(philo);
			ft_p_sleep(philo);
			ft_p_think(philo);
		}
	}
	return (NULL);
}

int	ft_check_death(t_philo *philo)
{
	if (philo->total_eaten == philo->must_eat)
		return (1);
	pthread_mutex_lock(philo->death);
	if (*philo->check_dead)
	{
		pthread_mutex_unlock(philo->death);
		return (1);
	}
	pthread_mutex_unlock(philo->death);
	if (ft_get_time() - philo->last_meal > \
		philo->time_to_die)
	{
		ft_p_print(philo, "died", 1);
		return (1);
	}
	return (0);
}
