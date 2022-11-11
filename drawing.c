/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:40:40 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/11 20:14:27 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

int	ft_abs(int n)
{
	if (n < 0)
		return(-n);
	return (n);
}

/****************************************
 *--- Bresenham algorithm for x1 < x2---*
 ***************************************/

void	draw_line_x(t_points p1, t_points p2, t_data img)
{
	int	dx;
	int	dy;
	int	e;
	int		ind[2];

	e = ft_abs(p2.x - p1.x);
	dx = 2 * e;
	dy = 2 * ft_abs(p2.y - p1.y);
	ind[X] = 1;
	ind[Y] = 1;
	if (p1.x > p2.x)
		ind[X] = -1;
	if (p1.y > p2.y)
		ind[Y] = -1;
	while (p1.x <= p2.x)
	{
		ft_mlx_pixel_put(&img, p1.x, p1.y, 0x000000ff + (0x00ff0000 - (0x00ff0000 * p2.alt * 20)));
		p1.x += ind[X];
		e -= dy;
		if (e < 0)
		{
			p1.y += ind[Y];
			e += dx;
		}
	}
}

/****************************************
 *--- Bresenham algorithm for y1 < y2---*
 ***************************************/

void	draw_line_y(t_points p1, t_points p2, t_data img)
{
	int	dx;
	int	dy;
	int	e;
	int	ind[2];

	e = ft_abs(p2.x - p1.x);
	dx = 2 * e;
	dy = 2 * ft_abs(p2.y - p1.y);
	ind[X] = 1;
	ind[Y] = 1;
	if (p1.x > p2.x)
		ind[X] = -1;
	if (p1.y > p2.y)
		ind[Y] = -1;
	while (p1.x >= p2.x)
	{
		ft_mlx_pixel_put(&img, p1.x, p1.y, 0x000000ff + (0x00ff0000 - (0x00ff0000 * p2.alt * 20)));
		p1.x += ind[X];
		e -= dy;
		if (e < 0)
		{
			p1.y += ind[Y];
			e += dx;
		}
	}
}
