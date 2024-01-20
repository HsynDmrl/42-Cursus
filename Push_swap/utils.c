/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:32:08 by hdemirel          #+#    #+#             */
/*   Updated: 2023/12/10 15:24:40 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_array_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	ft_stack_free(t_list *list)
{
	if (list != NULL)
	{
		if (list->stack_a != NULL)
			free(list->stack_a);
		if (list->stack_b != NULL)
			free(list->stack_b);
		if (list != NULL)
			free(list);
	}
}

int	ft_count_element(char **av)
{
	char	**array;
	int		i;
	int		j;
	int		count;

	i = 1;
	count = 0;
	while (av[i] != NULL)
	{
		array = ft_split(av[i], ' ');
		j = 0;
		while (array[j])
		{
			j++;
			count++;
		}
		i++;
		ft_array_free(array);
	}
	return (count);
}

int	ft_atoint(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[1] == '\0')
			ft_error_message();
		if (str[0] == '-')
			sign = -sign;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error_message();
		res = (res * 10) + str[i++] - '0';
		if ((res < -2147483648) || (res > 2147483647))
			ft_error_message();
	}
	res = res * sign;
	return (res);
}
