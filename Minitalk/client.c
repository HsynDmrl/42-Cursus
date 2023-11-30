/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:03:50 by hdemirel          #+#    #+#             */
/*   Updated: 2023/09/18 17:01:33 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_get_binary(int pid, char *str)
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
		pid = ft_atoi(argv[1]);
		ft_get_binary(pid, argv[2]);
	}
	return (0);
}
