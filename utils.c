/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:24:41 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/03 14:59:32 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	pixel_in_win(t_bresenham *data)
{
	if (data->x1 > WIDTH || data->y1 > HEIGHT
		|| data->x1 < 0 || data->y1 < 0)
		return (0);
	return (1);
}

int	ft_abs(int n)
{
	if (n < 0 && n >= INT_MIN)
		return (-n);
	return (n);
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dest = color;
}
