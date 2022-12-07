/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:54:19 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/07 09:26:51 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_bonus.h"

void	convert_point(t_event *events, t_points *point)
{
	const int	x = point->x_c;
	const int	y = point->y_c;
	const int	zoom = events->zoom;

	point->z = point->z_c * events->alt_os;
	point->x = ((x * zoom - y * zoom) * cos(0.6)) + events->x_os;
	point->y = ((x * zoom + y * zoom) * sin(0.6) - point->z)
		+ events->y_os;
}

void	*ft_new_image(t_mlx *fdf)
{
	fdf->img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (fdf->img.img == NULL)
		return (NULL);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &(fdf->img.bpp),
			&(fdf->img.line_len), &(fdf->img.endian));
	if (fdf->img.addr == NULL)
		return (NULL);
	return (fdf->img.img);
}

void	display_grid(t_mlx *fdf)
{
	fdf->img.img = ft_new_image(fdf);
	draw_grid(fdf);
	fdf->img.img = ft_new_image(fdf);
	draw_grid(fdf);
}

int	handle_key(int key, t_mlx *fdf)
{
	if (key == XK_Escape)
		destroy_win(fdf);
	if (key == 'a' || key == 'd' || key == 'w' || key == 's' || key == '='
		|| key == '-' || key == '8' || key == '7')
	{
		if (key == 'a')
			fdf->events->x_os -= 10;
		if (key == 'd')
			fdf->events->x_os += 10;
		if (key == 'w')
			fdf->events->y_os -= 10;
		if (key == 's')
			fdf->events->y_os += 10;
		if (key == '=')
			fdf->events->zoom++;
		if (key == '-')
			fdf->events->zoom--;
		if (key == '8')
			fdf->events->alt_os += 0.05;
		if (key == '7')
			fdf->events->alt_os -= 0.05;
		display_grid(fdf);
	}
	return (0);
}
