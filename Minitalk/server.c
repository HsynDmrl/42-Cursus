/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:03:57 by hdemirel          #+#    #+#             */
/*   Updated: 2023/09/18 16:57:09 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int s)
{
	static char		c = 0;
	static int		i = 128;

	if (s == SIGUSR1)
		c = c + i;
	i = i / 2;
	if (i == 0)
	{
		if (c >= 0 && c <= 127)
			write(1, &c, 1);
		c = 0;
		i = 128;
	}
}

int	main(void)
{
	ft_putstr_fd("SERVER PID:  ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (42)
		pause();
	return (0);
}
