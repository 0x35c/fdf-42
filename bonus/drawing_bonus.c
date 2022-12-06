/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:30:01 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/06 19:27:04 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic_bonus.h"

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

void	bresenham_1(t_bresenham *data, t_mlx *fdf, int color)
{
	int	i;

	i = 0;
	while (i <= data->ref_dx)
	{
		if (!(data->x1 > WIDTH || data->y1 > HEIGHT
				|| data->x1 < 0 || data->y1 < 0))
		{
			ft_mlx_pixel_put(&(fdf->img), data->x1, data->y1, color);
		}
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

void	bresenham_2(t_bresenham *data, t_mlx *fdf, int color)
{
	int	i;

	i = 0;
	while (i <= data->ref_dy)
	{
		if (!(data->x1 > WIDTH || data->y1 > HEIGHT
				|| data->x1 < 0 || data->y1 < 0))
		{
			ft_mlx_pixel_put(&(fdf->img), data->x1, data->y1, color);
		}
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

void	draw_line(t_points p1, t_points p2, t_mlx *fdf)
{
	t_bresenham	*data;
	int			color;

	if (p2.z)
		color = 0x00abec + 0x0000ff * p2.z * 3;
	else
		color = 0xb0c4ee;
	data = init_values(p1, p2);
	if (!data)
		return ;
	if (data->ref_dx > data->ref_dy)
		bresenham_1(data, fdf, color);
	else
		bresenham_2(data, fdf, color);
	free(data);
}

void	draw_grid(t_mlx *fdf)
{
	const t_map	info = fdf->events->info;
	int			i;

	i = 0;
	while (i + 1 < info.nb_points)
	{
		if ((i + 1) % info.nb_columns < info.nb_columns
			&& (i + 1) % info.nb_columns)
		{
			convert_point(fdf->events, &(fdf->events->points[i]));
			convert_point(fdf->events, &(fdf->events->points[i + 1]));
			draw_line(fdf->events->points[i], fdf->events->points[i + 1], fdf);
		}
		if (i + info.nb_columns < info.nb_points)
		{
			convert_point(fdf->events, &(fdf->events->points[i]));
			convert_point(fdf->events, &(fdf->events->points[i + 1]));
			draw_line(fdf->events->points[i],
				fdf->events->points[i + info.nb_columns], fdf);
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img.img);
}
