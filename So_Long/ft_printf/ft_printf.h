/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:46:52 by hdemirel          #+#    #+#             */
/*   Updated: 2023/07/22 19:04:39 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_control(va_list list, char c);
int	ft_printf(const char *str, ...);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putuint(unsigned int n);
int	ft_puthex(unsigned int n, char c);
int	ft_putpoint(unsigned long n, int p);

#endif