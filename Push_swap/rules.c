/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:29:19 by hdemirel          #+#    #+#             */
/*   Updated: 2023/12/09 17:36:07 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *arr)
{
	int	tmp;

	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
}

void	ft_swap_all(t_list *list, char c)
{
	if (c == 'a')
	{
		ft_swap(list->stack_a);
		write(1, "sa\n", 3);
	}
	else if (c == 'b')
	{
		ft_swap(list->stack_b);
		write(1, "sb\n", 3);
	}
	else if (c == 's')
	{
		ft_swap(list->stack_a);
		ft_swap(list->stack_b);
		write(1, "ss\n", 3);
	}
}

void	ft_push_a(t_list *list)
{
	int	i;
	int	j;

	i = list->size_a;
	list->size_a++;
	while (i > 0)
	{
		list->stack_a[i] = list->stack_a[i - 1];
		i--;
	}
	list->stack_a[0] = list->stack_b[0];
	j = 0;
	while (j < list->size_b - 1)
	{
		list->stack_b[j] = list->stack_b[j + 1];
		j++;
	}
	list->size_b--;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_list *list)
{
	int	i;
	int	j;

	i = list->size_b;
	list->size_b++;
	while (i > 0)
	{
		list->stack_b[i] = list->stack_b[i - 1];
		i--;
	}
	list->stack_b[0] = list->stack_a[0];
	j = 0;
	while (j < list->size_a - 1)
	{
		list->stack_a[j] = list->stack_a[j + 1];
		j++;
	}
	list->size_a--;
	write(1, "pb\n", 3);
}
