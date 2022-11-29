/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:34:16 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/29 17:23:02 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "struct.h"
# include <math.h>
# define WIDTH 960
# define HEIGHT 540
# define X 0
# define Y 1

int		ft_abs(int n);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_lines(t_points *p1, t_points *p2, t_mlx *win);

#endif
