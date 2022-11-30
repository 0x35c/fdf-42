/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:34:16 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/30 18:31:31 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"
# include <limits.h>
# define WIDTH 960
# define HEIGHT 540

int	ft_abs(int n);
int	pixel_in_win(t_bresenham *data);

#endif
