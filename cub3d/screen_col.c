/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_col.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:35:15 by oyozcan           #+#    #+#             */
/*   Updated: 2024/09/27 14:35:17 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	ft_pixel(t_data *data, double i)
{
	int	index;

	if (floor(data->hit.y) == data->hit.y)
	{
		index = 64 * floor(64 * i) + 64 * (data->hit.x - floor(data->hit.x));
		if (data->ray.w == 1)
			return (data->tex.so[index]);
		else if (data->ray.w == 0)
			return (data->tex.no[index]);
	}
	else if (floor(data->hit.x) == data->hit.x)
	{
		index = 64 * floor(64 * i) + 64 * (data->hit.y - floor(data->hit.y));
		if (data->ray.v == 1)
			return (data->tex.ea[index]);
		else if (data->ray.v == 0)
			return (data->tex.we[index]);
	}
	return (BLACK);
}

void	ft_column(t_data *data, int size)
{
	unsigned int	color;
	int				start;
	int				count;

	start = data->mlx.x * (data->mlx.y - size) / 2;
	if (size > data->mlx.y)
		count = (size - data->mlx.y) / 2;
	else
		count = 0;
	color = data->tex.c;
	while (data->ray.i < data->mlx.x * data->mlx.y)
	{
		if (data->ray.i >= start && count < size)
		{
			color = ft_pixel(data, (double)count / size);
			count++;
		}
		else if (count == size)
			color = data->tex.f;
		data->img.adr[data->ray.i] = mlx_get_color_value(data->mlx.ptr, color);
		data->ray.i += data->mlx.x;
	}
	data->ray.i -= data->mlx.x * data->mlx.y;
}

int	ft_size(t_data *data)
{
	double	correc;
	double	fisheye;

	fisheye = fabs((double)data->ray.i / (data->mlx.x / 2) - 1);
	fisheye *= 28 * M_PI / 180;
	correc = (double)data->hit.d * cos(fisheye);
	return (round(data->mlx.y / correc));
}

void	ft_stock(t_data *data)
{
	data->stk[data->ray.i].x = data->ray.x;
	data->stk[data->ray.i].y = data->ray.y;
	data->stk[data->ray.i].d = data->hit.d;
}
