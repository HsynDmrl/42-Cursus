/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:03:36 by hdemirel          #+#    #+#             */
/*   Updated: 2023/12/12 10:57:00 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checker(char **str)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (ft_isdigit(str[i][j]))
			{
				flag = 1;
				break ;
			}
		}
		if (flag == 0)
			ft_error_message();
		flag = 0;
	}
}

void	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((!ft_isdigit(argv[i][j]) && argv[i][j] != '+'
					&& argv[i][j] != '-' && argv[i][j] != ' ')
				|| (argv[i][j] == '+' && argv[i][j + 1] == '\0')
				|| (argv[i][j] == '-' && argv[i][j + 1] == '\0')
				|| (argv[i][j] == '+' && argv[i][j + 1] == ' ')
				|| (argv[i][j] == '-' && argv[i][j + 1] == ' '))
			{
				ft_error_message();
			}
			j++;
		}
	}
}

void	ft_check_duplicate(t_list *list)
{
	int	i;
	int	j;

	i = 0;
	while (i < list->size_a - 1)
	{
		j = i + 1;
		while (j < list->size_a)
		{
			if (list->stack_a[i] == list->stack_a[j])
			{
				ft_stack_free(list);
				ft_error_message();
			}
			j++;
		}
		i++;
	}
}

int	ft_check_sorted(t_list *list)
{
	int	i;

	i = 0;
	while (i < list->size_a - 1)
	{
		if (list->stack_a[i] > list->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_error_message(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
