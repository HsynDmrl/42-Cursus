/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:20:08 by hdemirel          #+#    #+#             */
/*   Updated: 2023/12/12 10:56:15 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*list;
	int		count_elements;

	ft_checker(av);
	list = malloc(sizeof * list);
	count_elements = ft_count_element(av);
	if (list == NULL || ac < 2)
		exit(1);
	ft_check_args(ac, av);
	ft_create_stack_b(list, count_elements);
	list->stack_a = ft_create_stack_a(av, count_elements);
	ft_check_duplicate(list);
	if (ft_check_sorted(list) == 1)
	{
		ft_stack_free(list);
		exit(0);
	}
	ft_create_index(list);
	ft_sort_all(list, list->size_a);
	if (ft_check_sorted(list) == 0)
	{
		ft_error_message();
	}
	ft_stack_free(list);
	return (0);
}
