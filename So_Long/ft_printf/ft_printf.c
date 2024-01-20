/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:57:24 by hdemirel          #+#    #+#             */
/*   Updated: 2023/07/22 19:05:16 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(va_list list, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = len + ft_putchar(va_arg(list, int));
	else if (c == 's')
		len = len + ft_putstr(va_arg(list, char *));
	else if (c == 'd' || c == 'i')
		len = len + ft_putnbr(va_arg(list, int));
	else if (c == 'u')
		len = len + ft_putuint(va_arg(list, unsigned int));
	else if (c == 'x' || c == 'X')
		len = len + ft_puthex(va_arg(list, unsigned int), c);
	else if (c == 'p')
		len = len + ft_putpoint(va_arg(list, unsigned long), 1);
	else
		return (ft_putchar('%'));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] != '%')
			len = len + ft_putchar(str[i]);
		if (str[i] == '%')
		{
			len = len + ft_control(list, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(list);
	return (len);
}
