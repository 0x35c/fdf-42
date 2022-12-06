/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:27:52 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/06 10:45:59 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "utils.h"
# include "../gnl/get_next_line.h"
# include <math.h>
# define ZOOM 1
# define ALT_OFFSET 0.6

void	coordinates(t_points *points, t_map info, int fd);
void	ft_free_split(char **strs);
t_map	info_mapping(int fd);

#endif
