/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:42:30 by hdemirel          #+#    #+#             */
/*   Updated: 2024/01/18 12:27:52 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "./minilibx_opengl_20191021/mlx.h"
# include "fcntl.h"
# include "stdlib.h"

typedef struct s_list
{
	void	*mlx;
	void	*win_ptr;
	void	*player_img_r;
	void	*player_img_l;
	void	*player_img_b;
	void	*player_img_t;
	void	*wall_img;
	void	*exit_img_c;
	void	*exit_img_o;
	void	*coin_img;
	void	*bg_img;
	char	**map;
	int		player_x;
	int		player_y;
	int		exit_count;
	int		coin_count;
	int		player_count;
	int		y_line_count;
	int		collected_coin;
	int		step_count;
	int		height;
	int		width;
}			t_list;

void		wall_error(t_list *list);
void		wall_error2(int x, int y, t_list *list);
void		create_map_img_to_window(t_list *list, int x, int y, void *img);
int			create_xpm_to_img_map(t_list *list);
void		map_line_count(t_list *list, char *map_file);
void		read_map(t_list *list, char *map_file);
void		ber_control(char *map_file, t_list *list);
void		map_char_control(t_list *list);
void		map_char_control2(t_list *list, int y, int x);
void		control_exit_player_count(t_list *list);
int			move(int keycode, t_list *list);
void		move_left(t_list *list);
void		move_right(t_list *list);
void		move_down(t_list *list);
void		move_up(t_list *list);
int			open_exit(t_list *list);
void		step_count(t_list *list);
void		path_control(t_list *list);
void		path_control_coin(t_list *list);
void		try_path_exit(char **map, int y, int x);
void		try_path_coin(char **map, int y, int x);
void		map_free(char **map);
char		**map_copy(t_list *list);
void		error_message(t_list *list);
void		file_control(char *map_file, t_list *list);
int			ft_exit(t_list *list);
void		map_info(t_list *list);
void		init_map(t_list *list);
void		error_control(t_list *list);
void		rectangle_control(t_list *list);
void		file_control2(void);
void		putexit(t_list *list, int x, int y);
void		create_character_to_img_map(t_list *list);
#endif
