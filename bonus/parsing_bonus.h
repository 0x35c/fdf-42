/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:27:52 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/06 14:12:55 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "utils_bonus.h"
# include "../libs/gnl/get_next_line.h"
# define ZOOM 1
# define ALT_OFFSET 0.6

void	coordinates(t_points *points, t_map info, int fd);
void	ft_free_split(char **strs);
t_map	info_mapping(int fd);

#endif
