/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:07:18 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/06 15:59:42 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bresenham	*init_values(t_points p1, t_points p2)
{
	t_bresenham	*data;

	data = ft_calloc(sizeof(t_bresenham), 1);
	if (!data)
		return (NULL);
	data->x1 = p1.x;
	data->y1 = p1.y;
	data->x2 = p2.x;
	data->y2 = p2.y;
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

void	bresenham_1(t_bresenham *data, t_mlx win, int color)
{
	int	i;

	i = 0;
	while (i <= data->ref_dx)
	{
		if (pixel_in_win(data))
			ft_mlx_pixel_put(&(win.img), data->x1, data->y1, color);
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

void	bresenham_2(t_bresenham *data, t_mlx win, int color)
{
	int	i;

	i = 0;
	while (i <= data->ref_dy)
	{
		if (pixel_in_win(data))
			ft_mlx_pixel_put(&(win.img), data->x1, data->y1, color);
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

void	draw_lines(t_points p1, t_points p2, t_mlx win)
{
	t_bresenham	*data;
	int			color;

	color = 0x0000ff + (0xff0000 - (0xff0000 * p2.z * 5));
	data = init_values(p1, p2);
	if (!data)
		return ;
	if (data->ref_dx > data->ref_dy)
		bresenham_1(data, win, color);
	else
		bresenham_2(data, win, color);
	free(data);
}

void	draw_grid(t_mlx *mlx, t_map info, t_points *points)
{
	int	i;

	i = 0;
	while (i + 1 < info.nb_points)
	{
		if ((i + 1) % info.nb_columns < info.nb_columns
			&& (i + 1) % info.nb_columns)
			draw_lines(points[i], points[i + 1], *mlx);
		if (i + info.nb_columns < info.nb_points)
			draw_lines(points[i], points[i + info.nb_columns], *mlx);
		i++;
	}
	free(points);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
}
