/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:32:03 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/29 18:25:28 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dest = color;
}

void	convert_points(t_points *p, int x, int y)
{
	p->x = (x - p->alt) / sqrt(2) * 10;
	p->y = (x + 2 * y + p->alt) / sqrt(6) * 10;
}

t_points	*parse(int ac, char **av)
{
	t_points	*head;
	int			fd;

	head = NULL;
	if (ac != 2)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 1)
		return (NULL);
	head = coordinates(head, fd);
	close(fd);
	return (head);
}

int	main(int ac, char **av)
{
	t_mlx			*win;
	const t_points	*head = parse(ac, av);
	t_points		*tmp;
	t_points		*point;
	int				x;
	int				y;

	win = ft_calloc(sizeof(t_mlx), 1);
	if (!win || !head)
		return (1);
	tmp = NULL;
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "Window test...");
	win->img.img = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	win->img.addr = mlx_get_data_addr(win->img.img, &(win->img.bpp),
			&(win->img.line_len), &(win->img.endian));
	tmp = (t_points *)head;
	y = 0;
	x = 0;
	while (tmp->next)
	{
		point = tmp;
		if (!point->eol)
		{
			convert_points(point, x, y);
			convert_points(point->next, x + 1, y);
			draw_lines(point, point->next, win);
			x++;
		}
		else
		{
			ft_printf("Line %d\n", y + 1);
			x = 0;
			y++;
		}
		tmp = tmp->next;
	}
	tmp = (t_points *)head;
	y = 0;
	x = 0;
	while (tmp->next)
	{
		point = tmp;
		if (!point->eol)
		{
			convert_points(point, x, y);
			convert_points(point->next, x, y + 1);
			draw_lines(point, point->next, win);
			x++;
			free(point);
		}
		else
		{
			ft_printf("Line %d\n", y + 1);
			x = 0;
			y++;
		}
		tmp = tmp->next;
	}
	free(tmp);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img.img, 0, 0);
	mlx_loop(win->mlx);
}
