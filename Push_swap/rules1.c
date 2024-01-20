/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:29:36 by hdemirel          #+#    #+#             */
/*   Updated: 2023/12/09 17:36:04 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(int *arr, int len)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = arr[0];
	while (i < len - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[i] = tmp;
}

void	ft_rr_all(t_list *list, char c)
{
	if (c == 'a')
	{
		ft_rotate(list->stack_a, list->size_a);
		write(1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		ft_rotate(list->stack_b, list->size_b);
		write(1, "rb\n", 3);
	}
	else if (c == 'r')
	{
		ft_rotate(list->stack_a, list->size_a);
		ft_rotate(list->stack_b, list->size_b);
		write(1, "rr\n", 3);
	}
}

void	ft_reverse_rotate(int *arr, int len)
{
	int	i;
	int	tmp;

	tmp = arr[len - 1];
	i = len - 1;
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = tmp;
}

void	ft_rrr_all(t_list *list, char c)
{
	if (c == 'a')
	{
		ft_reverse_rotate(list->stack_a, list->size_a);
		write(1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		ft_reverse_rotate(list->stack_b, list->size_b);
		write(1, "rrb\n", 4);
	}
	else if (c == 'r')
	{
		ft_reverse_rotate(list->stack_a, list->size_a);
		ft_reverse_rotate(list->stack_b, list->size_b);
		write(1, "rrr\n", 4);
	}
}
