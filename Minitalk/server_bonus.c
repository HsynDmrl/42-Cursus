/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:03:57 by hdemirel          #+#    #+#             */
/*   Updated: 2023/09/18 16:33:46 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_handler(int s, siginfo_t *info, void *content)
{
	static char		c = 0;
	static int		i = 128;

	(void)content;
	if (s == SIGUSR1)
		c = c + i;
	i = i / 2;
	if (i == 0)
	{
		write(1, &c, 1);
		c = 0;
		i = 128;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa_newsig;

	sa_newsig.sa_flags = SA_SIGINFO;
	sa_newsig.sa_sigaction = &ft_handler;
	pid = getpid();
	sigaction(SIGUSR1, &sa_newsig, NULL);
	sigaction(SIGUSR2, &sa_newsig, NULL);
	ft_putstr_fd("BONUS SERVER PID = ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (42)
		pause();
	return (0);
}
