/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:51:40 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/13 22:22:41 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	char	**points;
	int		y;
	int		x;
	int		fd;

	points = NULL;
	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 1)
		return (1);
	points = coordinates(fd);
	ft_printf("Coordonnées:\n");
	y = 0;
	while (points[y] != NULL)
	{
		x = 0;
		while (points[y][x] != '\0')
		{
			ft_printf("%d ", ft_atoi((const char *)&points[y][x]));
			x++;
		}
		ft_printf("\n");
		y++;
	}
	ft_printf("\n");
	close(fd);
	return (0);
}
