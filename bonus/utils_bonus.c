/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:24:41 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/06 19:27:40 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

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

int	check_args(int ac, int args_nb)
{
	if (ac > args_nb)
	{
		ft_exit_error(TOO_MUCH_ARGS);
		return (0);
	}
	else if (ac < args_nb)
	{
		ft_exit_error (TOO_FEW_ARGS);
		return (0);
	}
	else
		return (1);
}

void	ft_exit_error(int flag)
{
	if (flag == TOO_MUCH_ARGS)
		write(2, ERR_COLOR"Error: too much args\n"END, 41);
	else if (flag == TOO_FEW_ARGS)
		write(2, ERR_COLOR"Error: not enough args\n"END, 43);
	else if (flag == INVALID_FILE)
		write(2, ERR_COLOR"Error: invalid file\n"END, 40);
	else if (flag == ALLOC_ERR)
		write(2, ERR_COLOR"Allocation error\n"END, 36);
	exit(1);
}

int	destroy_win(t_mlx *fdf)
{
	mlx_loop_end(fdf->mlx);
	mlx_clear_window(fdf->mlx, fdf->mlx_win);
	mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->events->points);
	free(fdf->events);
	free(fdf->mlx);
	free(fdf);
	exit (0);
	return (1);
}
