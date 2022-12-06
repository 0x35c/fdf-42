/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:34:16 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/04 14:03:29 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "utils.h"

void	draw_lines(t_points p1, t_points p2, t_mlx win);
void	draw_grid(t_mlx *mlx, t_map info, t_points *points);

#endif
