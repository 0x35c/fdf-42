/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:58:40 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/06 17:58:45 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_BONUS_H
# define EVENTS_BONUS_H

# include "utils_bonus.h"
# include "graphic_bonus.h"
# include <X11/keysym.h>
# include <X11/X.h>

void	convert_point(t_event *events, t_points *point);
void	*ft_new_image(t_mlx *fdf);
int		handle_key(int key, t_mlx *fdf);

#endif
