/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:53:50 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/10 16:45:57 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "parsing.h"
# include "libft/libft.h"
# include <fcntl.h>
# include "minilibx-linux/mlx.h"

# define WIDTH 960
# define HEIGHT 540

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_data;

#endif
