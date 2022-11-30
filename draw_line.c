/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:32:03 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/30 18:22:30 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dest = color;
}

t_points	*parse(t_map info, int ac, char **av)
{
	t_points	*points;
	int			fd;

	if (ac != 2)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 1)
		return (NULL);
	points = ft_calloc(sizeof(t_points), info.nb_points);
	if (points == NULL)
		return (NULL);
	coordinates(points, info, fd);
	close(fd);
	return (points);
}

int	main(int ac, char **av)
{
	t_map		info;
	t_points	*points;
	t_mlx		win;
	int			fd;
	int			i;

	fd = open(av[1], O_RDONLY);
	if (fd < 1)
		return (1);
	info = info_mapping(fd);
	close(fd);
	points = parse(info, ac, av);
	if (points == NULL)
		return (1);
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, WIDTH, HEIGHT, "|-_WiReFrAmE_-|");
	win.img.img = mlx_new_image(win.mlx, WIDTH, HEIGHT);
	win.img.addr = mlx_get_data_addr(win.img.img, &(win.img.bpp),
			&(win.img.line_len), &(win.img.endian));
	i = 0;
	while (i + 1 < info.nb_points)
	{
		if ((i + 1) % info.nb_columns < info.nb_columns && (i + 1) % info.nb_columns)
			draw_lines(points[i], points[i + 1], win);
		if (i + info.nb_columns < info.nb_points)
			draw_lines(points[i], points[i + info.nb_columns], win);
		i++;
	}
	mlx_put_image_to_window(win.mlx, win.mlx_win, win.img.img, 0, 0);
	mlx_loop(win.mlx);
	close(fd);
	return (0);
}
