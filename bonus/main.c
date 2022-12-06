/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:32:03 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/06 10:45:09 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_points	*parse(t_map info, char **av)
{
	t_points	*points;
	int			fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 1)
		ft_exit_error(INVALID_FILE);
	points = ft_calloc(sizeof(t_points), info.nb_points);
	if (points == NULL)
		return (NULL);
	coordinates(points, info, fd);
	close(fd);
	return (points);
}

t_mlx	*win_init(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		return (NULL);
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		return (NULL);
	mlx->mlx_win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "|-_WiReFrAmE_-|");
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (mlx->mlx_win == NULL || mlx->img.img == NULL)
		return (NULL);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &(mlx->img.bpp),
			&(mlx->img.line_len), &(mlx->img.endian));
	if (mlx->img.addr == NULL)
		return (NULL);
	return (mlx);
}

int	destroy_win(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free(mlx);
	exit (0);
}

int	handle_key(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		destroy_win(mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_map		info;
	t_points	*points;
	t_mlx		*mlx;
	int			fd;

	check_args(ac, 2);
	fd = open(av[1], O_RDONLY);
	if (fd < 1)
		ft_exit_error(INVALID_FILE);
	info = info_mapping(fd);
	close(fd);
	points = parse(info, av);
	close(fd);
	if (points == NULL)
		ft_exit_error(ALLOC_ERR);
	mlx = win_init();
	if (mlx == NULL)
		ft_exit_error(ALLOC_ERR);
	draw_grid(mlx, info, points);
	mlx_hook(mlx->mlx_win, KeyRelease, KeyReleaseMask, &handle_key, mlx);
	mlx_hook(mlx->mlx_win, DestroyNotify, StructureNotifyMask,
		&destroy_win, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
