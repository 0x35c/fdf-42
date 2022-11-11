/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:27:52 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/10 14:18:34 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"

typedef struct s_points
{
	int				x;
	int				y;
	int				alt;
	struct s_points	*next;
}	t_points;
t_points   *coordinates(t_points *head, int fd);

#endif
