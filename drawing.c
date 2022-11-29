/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:07:18 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/29 18:19:20 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int n)
{
	if (n < 0 && n >= INT_MIN)
		return (-n);
	return (n);
}

t_bresenham	*init_values(t_points *p1, t_points *p2)
{
	t_bresenham	*data;

	data = ft_calloc(sizeof(t_bresenham), 1);
	if (!data)
		return (NULL);
	data->x1 = p1->x;
	data->y1 = p1->y;
	data->x2 = p2->x;
	data->y2 = p2->y;
	data->ex = ft_abs(data->x2 - data->x1);
	data->ey = ft_abs(data->y2 - data->y1);
	data->dx = 2 * data->ex;
	data->dy = 2 * data->ey;
	data->ref_dx = data->ex;
	data->ref_dy = data->ey;
	data->x_incr = 1;
	if (data->x1 > data->x2)
		data->x_incr = -1;
	data->y_incr = 1;
	if (data->y1 > data->y2)
		data->y_incr = -1;
	return (data);
}

void	bresenham_1(t_bresenham *data, t_mlx *win, int color)
{
	int	i;

	i = 0;
	while (i <= data->ref_dx)
	{
		ft_mlx_pixel_put(&(win->img), data->x1 + 50, data->y1 + 50, color);
		i++;
		data->x1 += data->x_incr;
		data->ex -= data->dy;
		if (data->ex < 0)
		{
			data->y1 += data->y_incr;
			data->ex += data->dx;
		}
	}
}

void	bresenham_2(t_bresenham *data, t_mlx *win, int color)
{
	int	i;

	i = 0;
	while (i <= data->ref_dy)
	{
		ft_mlx_pixel_put(&(win->img), data->x1 + 50, data->y1 + 50, color);
		i++;
		data->y1 += data->y_incr;
		data->ey -= data->dx;
		if (data->ey < 0)
		{
			data->x1 += data->x_incr;
			data->ey += data->dy;
		}
	}
}

void	draw_lines(t_points *p1, t_points *p2, t_mlx *win)
{
	t_bresenham	*data;
	int			color;

	color = 0x000000ff + (0x00ff0000 - (0x00ff0000 * p2->alt * 20));
	data = init_values(p1, p2);
	if (!data)
		return ;
	if (data->ref_dx > data->ref_dy)
		bresenham_1(data, win, color);
	else
		bresenham_2(data, win, color);
}
