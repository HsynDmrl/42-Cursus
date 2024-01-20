/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:31:34 by hdemirel          #+#    #+#             */
/*   Updated: 2023/12/10 16:57:20 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_all(t_list *list, int len)
{
	if (len == 2)
		ft_sort_two(list);
	else if (len == 3)
		ft_sort_three(list);
	else if (len > 3 && len <= 5)
		ft_sort_four_five(list);
	else if (len > 5)
		radix_sort(list);
}

void	ft_sort_two(t_list *list)
{
	if (list->stack_a[0] > list->stack_a[1])
	{
		ft_swap_all(list, 'a');
	}
}

void	ft_sort_three(t_list *list)
{
	if (list->stack_a[0] > list->stack_a[1]
		&& list->stack_a[0] > list->stack_a[2])
	{
		if (list->stack_a[1] > list->stack_a[2])
		{
			ft_swap_all(list, 'a');
			ft_rrr_all(list, 'a');
		}
		else
			ft_rr_all(list, 'a');
	}
	else if ((list->stack_a[1] > list->stack_a[0]
			&& list->stack_a[1] > list->stack_a[2]))
	{
		if (list->stack_a[0] > list->stack_a[2])
			ft_rrr_all(list, 'a');
		else
		{
			ft_swap_all(list, 'a');
			ft_rr_all(list, 'a');
		}
	}
	else
		ft_swap_all(list, 'a');
}

void	ft_sort_four_five(t_list *list)
{
	while (list->size_b <= 1)
	{
		if (list->stack_a[0] == 0 || list->stack_a[0] == 1)
			ft_push_b(list);
		else
			ft_rr_all(list, 'a');
	}
	if (list->stack_b[0] == 0)
		ft_swap_all(list, 'b');
	if (list->size_a == 3 && ft_check_sorted(list) == 0)
		ft_sort_three(list);
	else
		ft_sort_two(list);
	ft_push_a(list);
	ft_push_a(list);
}
