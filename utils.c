/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:24:41 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/30 18:32:55 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	pixel_in_win(t_bresenham *data)
{
	if (data->x1 > WIDTH || data->y1 > HEIGHT)
		return (0);
	return (1);
}

int	ft_abs(int n)
{
	if (n < 0 && n >= INT_MIN)
		return (-n);
	return (n);
}
