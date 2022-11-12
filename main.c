/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:51:40 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/10 15:51:23 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_points	**matrix;
	int			y;
	int			x;
	int			fd;

	matrix = NULL;
	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 1)
		return (1);
	coordinates(&matrix, fd);
	ft_printf("Coordonnées:\n");
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x].eol !=1)
		{
			ft_printf("%d ", matrix[y][x].alt);
			//free(&matrix[y][x]);
			x++;
		}
		ft_printf("\n");
		//free(&matrix[y]);
		y++;
	}
	ft_printf("\n");
	close(fd);
	return (0);
}
