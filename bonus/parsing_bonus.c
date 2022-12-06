/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:29:58 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/06 17:15:40 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

void	ft_new_point(t_points *point, char *z, int x, int y)
{
	point->z_c = ft_atoi(z);
	point->x_c = x;
	point->y_c = y;
}

void	ft_free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	coordinates(t_points *points, t_map info, int fd)
{
	char		*str;
	char		**split_str;
	int			y;
	int			x;

	str = NULL;
	str = get_next_line(fd);
	y = 0;
	while (str)
	{
		split_str = ft_split(str, ' ');
		free(str);
		x = 0;
		while (split_str[x])
		{
			ft_new_point(&points[x + y * info.nb_columns], split_str[x], x, y);
			x++;
		}
		ft_free_split(split_str);
		str = get_next_line(fd);
		y++;
	}
}
