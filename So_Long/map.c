/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:41:15 by hdemirel          #+#    #+#             */
/*   Updated: 2024/01/13 13:41:15 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_line_count(t_list *list, char *map_file)
{
	char	*line;
	int		fd;
	int		line_count;

	line_count = 0;
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
	{
		error_message(list);
	}
	while (line)
	{
		free(line);
		line_count++;
		line = get_next_line(fd);
	}
	list->y_line_count = line_count;
	close(fd);
}

void	read_map(t_list *list, char *map_file)
{
	char	*str;
	int		i;
	int		fd;

	map_line_count(list, map_file);
	list->map = malloc((list->y_line_count + 1) * sizeof(char *));
	if (!list->map)
		return ;
	fd = open(map_file, O_RDONLY);
	i = 0;
	while (i < list->y_line_count)
	{
		str = get_next_line(fd);
		list->map[i] = str;
		i++;
	}
	list->map[i] = NULL;
	close(fd);
}

int	create_xpm_to_img_map(t_list *list)
{
	int	x;
	int	y;

	create_character_to_img_map(list);
	list->coin_img = mlx_xpm_file_to_image(list->mlx, "textures/coin.xpm", &x,
			&y);
	list->exit_img_c = mlx_xpm_file_to_image(list->mlx, "textures/exit_c.xpm",
			&x, &y);
	list->exit_img_o = mlx_xpm_file_to_image(list->mlx, "textures/exit_o.xpm",
			&x, &y);
	list->wall_img = mlx_xpm_file_to_image(list->mlx, "textures/wall.xpm", &x,
			&y);
	list->bg_img = mlx_xpm_file_to_image(list->mlx, "textures/background.xpm",
			&x, &y);
	if (!list->bg_img || !list->coin_img || !list->exit_img_c
		|| !list->player_img_r || !list->player_img_l || !list->exit_img_o
		|| !list->player_img_t || !list->player_img_b || !list->wall_img)
		return (1);
	return (0);
}

void	putexit(t_list *list, int x, int y)
{
	if (list->coin_count - list->collected_coin == 0)
		mlx_put_image_to_window(list->mlx, list->win_ptr,
			list->exit_img_o, 60 * x, 60 * y);
	else
		mlx_put_image_to_window(list->mlx, list->win_ptr,
			list->exit_img_c, 60 * x, 60 * y);
}

void	create_map_img_to_window(t_list *list, int x, int y, void *img)
{
	y = -1;
	while (list->map[++y] != NULL)
	{
		x = 0;
		while (list->map[y][x] && list->map[y][x] != '\n')
		{
			mlx_put_image_to_window(list->mlx, list->win_ptr, list->bg_img, 60
				* x, 60 * y);
			if (list->map[y][x] == 'C')
				mlx_put_image_to_window(list->mlx, list->win_ptr,
					list->coin_img, 60 * x, 60 * y);
			else if (list->map[y][x] == 'E')
				putexit(list, x, y);
			else if (list->map[y][x] == 'P')
				mlx_put_image_to_window(list->mlx, list->win_ptr,
					img, 60 * (list->player_x), 60
					* (list->player_y));
			else if (list->map[y][x] == '1')
				mlx_put_image_to_window(list->mlx, list->win_ptr,
					list->wall_img, 60 * x, 60 * y);
			x++;
		}
	}
}
