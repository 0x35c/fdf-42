/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:51:35 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/07 09:30:33 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
	t_mlx	*fdf;

	fdf = malloc(sizeof(t_mlx));
	if (fdf == NULL)
		return (NULL);
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		return (NULL);
	fdf->mlx_win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "|-_WiReFrAmE_-|");
	if (fdf->mlx_win == NULL)
		return (NULL);
	fdf->events = malloc(sizeof(t_event));
	if (fdf->events == NULL)
		return (NULL);
	fdf->events->zoom = 1;
	fdf->events->x_os = WIDTH / 2;
	fdf->events->y_os = 100;
	fdf->events->alt_os = 1;
	return (fdf);
}

int	main(int ac, char **av)
{
	t_mlx		*fdf;
	int			fd;

	check_args(ac, 2);
	fdf = win_init();
	if (fdf == NULL)
		ft_exit_error(ALLOC_ERR);
	fd = open(av[1], O_RDONLY);
	if (fd < 1)
		ft_exit_error(INVALID_FILE);
	fdf->events->info = info_mapping(fd);
	close(fd);
	fdf->events->points = parse(fdf->events->info, av);
	if (fdf->events->points == NULL)
		ft_exit_error(ALLOC_ERR);
	display_grid(fdf);
	mlx_hook(fdf->mlx_win, KeyPress, KeyPressMask, &handle_key, fdf);
	mlx_hook(fdf->mlx_win, DestroyNotify, StructureNotifyMask,
		&destroy_win, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
