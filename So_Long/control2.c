/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:40:46 by hdemirel          #+#    #+#             */
/*   Updated: 2024/01/13 15:03:46 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_char_control(t_list *list)
{
	int	y;
	int	x;

	y = -1;
	list->exit_count = 0;
	list->player_count = 0;
	list->coin_count = 0;
	list->collected_coin = 0;
	list->step_count = 0;
	while (list->map[++y])
	{
		x = 0;
		while (list->map[y][x] != '\n' && list->map[y][x] != '\0')
		{
			if (list->map[y][x] == 'E' || list->map[y][x] == 'P'
				|| list->map[y][x] == 'C' || list->map[y][x] == '1'
				|| list->map[y][x] == '0')
			{
				map_char_control2(list, y, x);
				x++;
			}
			else
				error_message(list);
		}
	}
}

void	map_char_control2(t_list *list, int y, int x)
{
	if (list->map[y][x] == 'E')
		list->exit_count++;
	else if (list->map[y][x] == 'P')
	{
		list->player_count++;
		list->player_y = y;
		list->player_x = x;
	}
	else if (list->map[y][x] == 'C')
		list->coin_count++;
}

void	control_exit_player_count(t_list *list)
{
	if (list->exit_count != 1)
		error_message(list);
	if (list->player_count != 1)
		error_message(list);
	if (list->coin_count < 1)
		error_message(list);
}

int	ft_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

void	rectangle_control(t_list *list)
{
	int	y;
	int	len;

	y = 0;
	len = ft_len(list->map[0]);
	while (y < list->height && list->map[y] != NULL)
	{
		if (ft_len(list->map[y]) != len)
		{
			error_message(list);
		}
		y++;
	}
}
