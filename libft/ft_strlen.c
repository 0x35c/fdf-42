/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:27:34 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/13 22:28:04 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlen_2d(char **s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}
