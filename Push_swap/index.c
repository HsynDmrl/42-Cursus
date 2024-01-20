/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:40:30 by hdemirel          #+#    #+#             */
/*   Updated: 2023/12/12 10:53:17 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_stack_b(t_list *list, int count_elements)
{
	list->size_a = count_elements;
	list->stack_b = malloc(list->size_a * sizeof * list->stack_b);
	if (list->stack_b == NULL)
	{
		ft_stack_free(list);
		ft_error_message();
	}
}

int	*ft_create_stack_a(char **av, int count_elements)
{
	char	**array;
	int		i;
	int		j;
	int		x;
	int		*res;

	i = 0;
	x = 0;
	res = malloc(sizeof(int) * (count_elements));
	if (!res)
	{
		free(res);
		ft_error_message();
	}
	while (av[++i] != NULL)
	{
		if (av[i][0] == '\0')
			ft_error_message();
		array = ft_split(av[i], ' ');
		j = 0;
		while (array[j] != NULL)
			res[x++] = ft_atoint(array[j++]);
		ft_array_free(array);
	}
	return (res);
}

void	ft_create_index(t_list *list)
{
	int	i;
	int	j;
	int	count;
	int	*index_a;

	index_a = malloc(list->size_a * sizeof * index_a);
	if (index_a == NULL)
	{
		ft_stack_free(list);
		ft_error_message();
	}
	i = -1;
	while (++i < list->size_a)
	{
		count = 0;
		j = -1;
		while (++j < list->size_a)
			if (list->stack_a[i] > list->stack_a[j])
				count++;
		index_a[i] = count;
	}
	i = -1;
	while (++i < list->size_a)
		list->stack_a[i] = index_a[i];
	free(index_a);
}
