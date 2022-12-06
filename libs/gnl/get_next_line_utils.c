/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:34:14 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/03 16:21:40 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/*****************************
 *--- Secure malloc initᵒ ---*
 ****************************/

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	int		i;
	int		n;

	n = nmemb * size;
	if (n / nmemb != size)
		return (NULL);
	array = malloc(n);
	if (!array)
	{
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		array[i] = '\0';
		i++;
	}
	return (array);
}

/*****************************
 *-- Copy buf with nl stop --*
 ****************************/

void	cpy_buf_nl(char *buf, char *str, int i)
{
	int	j;

	j = 0;
	while (buf[j])
	{
		str[i] = buf[j];
		if (buf[j] == '\n')
			return ;
		i++;
		j++;
	}
}

/*****************************
 *-- Alloc prev line + buf --*
 ****************************/

char	*ft_strjoin_gnl(char *line, char *buf)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_calloc(ft_strlen(line) + ft_strlen(buf) + 1, 1);
	if (!str)
		return (NULL);
	if (line)
	{
		while (line[j])
		{
			str[i] = line[j];
			i++;
			j++;
		}
		free(line);
	}
	cpy_buf_nl(buf, str, i);
	return (str);
}

/*****************************
 *-- Save the buf after nl --*
 ****************************/

void	ft_substr_gnl(char *buf)
{
	int	i;
	int	j;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	if (!buf[i])
		return ;
	i++;
	j = 0;
	while (buf[i])
	{
		buf[j] = buf[i];
		i++;
		j++;
	}
	buf[j] = '\0';
}
