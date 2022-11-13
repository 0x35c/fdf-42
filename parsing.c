/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:29:58 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/13 22:43:49 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

char	**coordinates(int fd)
{
	char	*str;
	char	**split_str;
	char	**points;

	str = NULL;
	points = NULL;
	str = get_next_line(fd);
	while (str)
	{
		split_str = ft_split(str, ' ');
		points = ft_strjoin_2d(points, split_str);
		ft_free(split_str, str);
		str = get_next_line(fd);
	}
	if (str)
		free(str);
	return (points);
}
