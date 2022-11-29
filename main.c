/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:51:40 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/29 17:01:32 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_points	*head;
	t_points	*tmp1;
	t_points	*tmp2;
	int			y;
	int			fd;

	head = NULL;
	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 1)
		return (1);
	if (head == NULL)
		head = coordinates(head, fd);
	ft_printf("Coordonnées:\n");
	tmp1 = head;
	y = 0;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		if (tmp2->y > y)
		{
			ft_printf("\n");
			y++;
		}
		ft_printf("%d ", tmp2->alt);
		free(tmp2);
	}
	ft_printf("\n");
	free(tmp1);
	close(fd);
	return (0);
}
