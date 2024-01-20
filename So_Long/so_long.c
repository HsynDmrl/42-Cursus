/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:42:17 by hdemirel          #+#    #+#             */
/*   Updated: 2024/01/18 13:22:16 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_list	*list;

	if (ac == 2)
	{
		list = malloc(sizeof(t_list));
		if (!list)
			return (0);
		file_control(av[1], list);
		read_map(list, av[1]);
		ber_control(av[1], list);
		map_info(list);
		rectangle_control(list);
		error_control(list);
		init_map(list);
		mlx_hook(list->win_ptr, 2, 0, move, list);
		mlx_hook(list->win_ptr, 17, 0, ft_exit, list);
		mlx_loop(list->mlx);
	}
	else
		write(1, "wrong arguments", 16);
}
