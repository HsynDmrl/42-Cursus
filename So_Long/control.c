/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:40:19 by hdemirel          #+#    #+#             */
/*   Updated: 2024/01/13 13:40:19 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_error(t_list *list)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (list->map[0][x] != '\n' && list->map[0][x])
	{
		if (list->map[0][x] != '1')
			error_message(list);
		x++;
	}
	x--;
	while (list->map[y] != NULL)
	{
		if (list->map[y][x] != '1' || list->map[y][0] != '1')
			error_message(list);
		y++;
	}
	y--;
	x = 0;
	wall_error2(x, y, list);
}

void	wall_error2(int x, int y, t_list *list)
{
	while (list->map[y][x] != '\n' && list->map[y][x])
	{
		if (list->map[y][x] != '1')
			error_message(list);
		x++;
	}
	x--;
}

void	ber_control(char *map_file, t_list *list)
{
	int	len;

	(void)list;
	len = ft_strlen(map_file) - 1;
	if (map_file[len] != 'r' || map_file[len - 1] != 'e'
		|| map_file[len - 2] != 'b' || map_file[len - 3] != '.')
		error_message(list);
	if (map_file[len - 4] == '/' || ft_strlen(map_file) < 5)
		error_message(list);
}

void	file_control(char *map_file, t_list *list)
{
	int	fd;

	fd = open(map_file, O_RDWR);
	if (fd <= 0)
	{
		close(fd);
		error_message(list);
	}
	close(fd);
	file_control2();
}

void	file_control2(void)
{
	if (open("textures/coin.xpm", O_RDONLY) == -1 || open("textures/exit_c.xpm",
			O_RDONLY) == -1 || open("textures/cRight.xpm", O_RDONLY) == -1
		|| open("textures/wall.xpm", O_RDONLY) == -1
		|| open("textures/background.xpm", O_RDONLY) == -1
		|| open("textures/cTop.xpm", O_RDONLY) == -1
		|| open("textures/cLeft.xpm", O_RDONLY) == -1
		|| open("textures/cBot.xpm", O_RDONLY) == -1)
	{
		write(1, "File Error!", 12);
		exit(1);
	}
}
