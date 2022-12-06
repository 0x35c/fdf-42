/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:29:58 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/06 13:30:58 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

t_map	info_mapping(int fd)
{
	t_map	info_map;
	char	*str;
	char	**split_str;
	int		i;

	info_map.nb_points = 0;
	info_map.nb_lines = 1;
	str = get_next_line(fd);
	while (str != NULL)
	{
		split_str = ft_split(str, ' ');
		free(str);
		i = 0;
		while (split_str[i])
		{
			info_map.nb_columns = i + 1;
			i++;
		}
		info_map.nb_lines++;
		info_map.nb_points += info_map.nb_columns;
		ft_free_split(split_str);
		str = get_next_line(fd);
	}
	return (info_map);
}
