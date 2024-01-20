/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:30:45 by hdemirel          #+#    #+#             */
/*   Updated: 2023/12/05 15:10:40 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_num(t_list *list)
{
	int	max;
	int	i;

	i = 0;
	max = list->stack_a[0];
	while (i < list->size_a)
	{
		if (list->stack_a[i] > max)
			max = list->stack_a[i];
		i++;
	}
	return (max);
}

int	ft_max_digit(int max)
{
	int	bit_count;

	bit_count = 0;
	while (max > 0)
	{
		max /= 2;
		bit_count++;
	}
	return (bit_count);
}

void	radix_sort(t_list *list)
{
	int	i;
	int	j;
	int	size;
	int	max;
	int	max_digit;

	i = 0;
	size = list->size_a;
	max = ft_max_num(list);
	max_digit = ft_max_digit(max);
	while (i < max_digit)
	{
		j = 0;
		while (j < size)
		{
			if (((list->stack_a[0] >> i) & 1) == 1)
				ft_rr_all(list, 'a');
			else
				ft_push_b(list);
			j++;
		}
		while (list->size_b != 0)
			ft_push_a(list);
		i++;
	}
}
