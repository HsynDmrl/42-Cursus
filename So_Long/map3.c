/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:19:30 by hdemirel          #+#    #+#             */
/*   Updated: 2024/01/18 11:59:00 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_info(t_list *list)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (list->map[y] != NULL)
	{
		while (list->map[y][x] && list->map[y][x] != '\n')
		{
			x++;
			list->width = x;
		}
		y++;
		list->height = y;
		x = 0;
	}
	if (list->width > 42 || list->height > 22)
		error_message(list);
}

void	create_character_to_img_map(t_list *list)
{
	int	x;
	int	y;

	list->player_img_r = mlx_xpm_file_to_image(list->mlx, "textures/cRight.xpm",
			&x, &y);
	list->player_img_l = mlx_xpm_file_to_image(list->mlx, "textures/cleft.xpm",
			&x, &y);
	list->player_img_t = mlx_xpm_file_to_image(list->mlx, "textures/cTop.xpm",
			&x, &y);
	list->player_img_b = mlx_xpm_file_to_image(list->mlx, "textures/cBot.xpm",
			&x, &y);
}
