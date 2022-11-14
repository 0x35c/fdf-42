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
	x = 0;
	while (points[x] != NULL || points[x + 1] != NULL)
	{
		if (points[x] == NULL)
			ft_printf("\n");
		else
		{
			ft_printf("%d ", ft_atoi(points[x]));
			free(points[x]);
		}
		x++;
	}
	free(points);
	ft_printf("\n");
	close(fd);
	return (0);
}
