/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:43:12 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/13 22:47:09 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = 0;
	return (str);
}

char	**ft_strjoin_2d(char **s1, char **s2)
{
	int		i;
	int		j;
	char	**str;

	if (!s2)
		return (0);
	str = malloc(sizeof(char **) * (ft_strlen_2d(s1) + ft_strlen_2d(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1 && s1[i++])
	{
		str[j] = ft_strdup(s1[i]);
		j++;
	}
	free(s1);
	i = -1;
	while (*s2 && s2[i++])
	{
		str[j] = ft_strdup(s2[i]);
		j++;
	}
	str[j] = NULL;
	return (str);
}
