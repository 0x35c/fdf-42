/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:29:58 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/13 22:43:49 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

size_t  ft_strlen_2d(char **s)
{
    size_t  i;

    if (!s)
        return (0);
    i = 0;
	while (s[i] != NULL)
	{
		while (s[i] != NULL)
			i++;
		i++;
	}
    return (i);
}

char    **ft_strjoin_2d(char **s1, char **s2)
{
    int     i;
    int     j;
    char    **str;

    if (!s2)
        return (NULL);
    str = ft_calloc(ft_strlen_2d(s1) + ft_strlen_2d(s2) + 1, sizeof(char **));
    if (!str)
        return (NULL);
    i = -1;
    j = 0;
    while (s1 && (s1[++i] != NULL || s1[i + 1] != NULL))
    {
        str[j] = ft_strdup(s1[i]);
		free(s1[i]);
        j++;
    }
	if (s1)
		j++;
	free(s1);
    i = -1;
    while (s2[++i] != NULL)
    {
        str[j] = ft_strdup(s2[i]);
        j++;
    }
    return (str);
}

void	ft_free(char **strs, char *str)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	free(str);
}

char	**coordinates(int fd)
{
	char	*str;
	char	**split_str;
	char	**points;
	//int		i = 0;

	str = NULL;
	points = NULL;
	str = get_next_line(fd);
	while (str)
	{
		split_str = ft_split(str, ' ');
		points = ft_strjoin_2d(points, split_str);
		/*while (points[i])
		{
			ft_printf("%s ", points[i]);
			i++;
		}
		ft_printf("\n");
		i++;*/
		ft_free(split_str, str);
		str = get_next_line(fd);
	}
	if (str)
		free(str);
	return (points);
}
