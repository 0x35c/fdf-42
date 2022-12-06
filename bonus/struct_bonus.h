/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:49:58 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/06 18:54:28 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_data;

typedef struct s_map
{
	int	nb_points;
	int	nb_columns;
	int	nb_lines;
}		t_map;

typedef struct s_points
{
	int		x;
	int		y;
	float	z;
	int		x_c;
	int		y_c;
	int		z_c;
}		t_points;

typedef struct s_event
{
	int			zoom;
	int			x_os;
	int			y_os;
	float		alt_os;
	t_points	*points;
	t_map		info;
}				t_event;

typedef struct s_bresenham
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	ex;
	int	ey;
	int	dx;
	int	dy;
	int	ref_dx;
	int	ref_dy;
	int	x_incr;
	int	y_incr;
}		t_bresenham;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_event	*events;
}			t_mlx;

#endif
