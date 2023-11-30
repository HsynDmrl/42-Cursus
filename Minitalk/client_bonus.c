/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:03:50 by hdemirel          #+#    #+#             */
/*   Updated: 2023/09/18 17:15:27 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_argv;

void	ft_message(int sig)
{
	if (sig == SIGUSR1)
		g_argv--;
	if (g_argv == 0)
		ft_putstr_fd("Message successful!\n", 1);
}

void	ft_binary(int pid, char *str)
{
	int	i;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			if (*str >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(42);
			i--;
		}
		str++;
	}
}

void	ft_putinfo(char **argv)
{
	ft_putstr_fd("BONUS Client PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\nSent: ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putstr_fd(" byte\n", 1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Wrong arguments! Type ./client_bonus PID words", 2);
		return (1);
	}
	else if (argc == 3)
	{
		g_argv = ft_strlen(argv[2]);
		pid = ft_atoi(argv[1]);
		ft_putinfo(argv);
		signal(SIGUSR1, ft_message);
		signal(SIGUSR2, ft_message);
		ft_binary(pid, argv[2]);
	}
	return (0);
}
