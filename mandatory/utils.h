/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:34:16 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/06 10:37:43 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"
# include "../libft/libft.h"
# include <limits.h>
# define WIDTH 900
# define HEIGHT 900
# define TOO_MUCH_ARGS 1
# define TOO_FEW_ARGS 2
# define INVALID_FILE 3
# define ALLOC_ERR 4
# define ERR_COLOR "\x1b[38;2;200;0;20m"
# define END "\x1b[0m"

int		pixel_in_win(t_bresenham *data);
int		ft_abs(int n);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
int		check_args(int ac, int args_nb);
void	ft_exit_error(int flag);

#endif
