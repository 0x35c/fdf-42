/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:29:58 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/10 15:46:38 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_points	*ft_new_element(char *alt, int x, int y)
{
	t_points	*node;

	node = NULL;
	node = malloc(sizeof *node);
	node->alt = ft_atoi(alt);
	node->x = x;
	node->y = y;
	node->eol = 0;
	return (node);
}

t_points	**ft_alloc_y(char **split_str)
{
	int		i;
	t_points	**tmp;

	i = 0;
	while (split_str[i])
		i++;
	tmp = malloc(i * sizeof **tmp);
	return (tmp);
}

void	ft_free(char **strs, char *str)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	free(str);
}

void	coordinates(t_points ***matrix, int fd)
{
	char		*str;
	char		**split_str;
	int		x;
	int		y;

	str = NULL;
	str = get_next_line(fd);
	y = 0;
	while (str)
	{
		split_str = ft_split(str, ' ');
		matrix[y] = ft_alloc_y(split_str);
		x = 0;
		while (split_str[x] != NULL)
		{
			matrix[y][x] = ft_new_element(split_str[x], x, y);
			ft_printf("%d ", matrix[y][x]->alt);
			//ft_printf("Coordonnées: %d %d %d\n", matrix[y][x]->x, matrix[y][x]->y, matrix[y][x]->alt);
			x++;
		}
		matrix[y][x - 1]->eol = 1;
		if (matrix[y][x - 1]->eol == 1)
			ft_printf("\n");
		ft_free(split_str, str);
		str = get_next_line(fd);
		y++;
	}
	if (str)
		free(str);
}
