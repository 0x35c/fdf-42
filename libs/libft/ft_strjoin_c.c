/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:43:12 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/25 17:02:05 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_c(char *s1, char c)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(ft_strlen(s1) + 2);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			str[j] = s1[i];
			j++;
			i++;
		}
		free(s1);
	}
	str[j] = c;
	str[j + 1] = '\0';
	return (str);
}
