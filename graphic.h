/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:34:16 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/30 18:31:07 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "utils.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_lines(t_points p1, t_points p2, t_mlx win);

#endif
