/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:41:03 by hdemirel          #+#    #+#             */
/*   Updated: 2024/01/13 13:43:34 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_control(t_list *list)
{
	wall_error(list);
	map_char_control(list);
	control_exit_player_count(list);
	path_control_coin(list);
	path_control(list);
}
