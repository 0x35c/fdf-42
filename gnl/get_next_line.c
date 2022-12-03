/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:34:02 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/03 16:21:46 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*****************************
 *- Rd + check buf function -*
 ****************************/

int	read_fd(int fd, char *buf)
{
	int	check_read;

	check_read = read(fd, buf, BUFFER_SIZE);
	if (check_read > 0)
	{
		buf[check_read] = '\0';
		return (check_read);
	}
	else
		return (0);
}

/*****************************
 *- Find '\n' char function -*
 ****************************/

int	find_nl(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

/*****************************
 *---- Main gnl function ----*
 ****************************/

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	static int	check_read;

	line = NULL;
	while (!find_nl(buf))
	{
		if (buf[0] && !check_read)
			buf[0] = '\0';
		line = ft_strjoin_gnl(line, buf);
		check_read = read_fd(fd, buf);
		if (!check_read)
			break ;
	}
	if (find_nl(buf))
		line = ft_strjoin_gnl(line, buf);
	if (line && !line[0])
	{
		free(line);
		return (NULL);
	}
	ft_substr_gnl(buf);
	return (line);
}
