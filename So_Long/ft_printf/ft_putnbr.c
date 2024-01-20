/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:11:00 by hdemirel          #+#    #+#             */
/*   Updated: 2023/07/22 19:06:43 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		len;
	long	nbr;

	len = 0;
	nbr = n;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		len = len + ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr < 10)
	{
		len = len + ft_putchar(nbr + '0');
	}
	if (nbr > 9)
	{
		len = len + ft_putnbr(nbr / 10);
		len = len + ft_putnbr(nbr % 10);
	}
	return (len);
}

int	ft_putuint(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len = len + ft_putuint(n / 10);
	write(1, &"0123456789"[n % 10], 1);
	return (len + 1);
}

int	ft_puthex(unsigned int n, char c)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, c);
	if (c == 'X')
		len += ft_putchar("0123456789ABCDEF"[n % 16]);
	if (c == 'x')
		len += ft_putchar("0123456789abcdef"[n % 16]);
	return (len);
}

int	ft_putpoint(unsigned long n, int p)
{
	int	len;

	len = 0;
	if (p == 1)
	{
		len = len + write(1, "0x", 2);
		if (n == 0)
		{
			len += write(1, "0", 1);
			return (len);
		}
		p = 0;
	}
	if (n >= 16)
		len = len + ft_putpoint(n / 16, 0);
	len += ft_putchar("0123456789abcdef"[n % 16]);
	return (len);
}
