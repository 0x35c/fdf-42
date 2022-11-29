/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:29:58 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/29 17:02:50 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_points	*ft_new_node(char *alt, int x, int y)
{
	t_points	*node;

	node = NULL;
	node = malloc(sizeof(t_points));
	if (node == NULL)
	{
		return (0);
	}
	node->alt = ft_atoi(alt);
	node->x = x;
	node->y = y;
	node->eol = 0;
	node->next = 0;
	return (node);
}

t_points	*ft_lstadd_node(t_points **first_node, t_points *new)
{
	t_points	*tmp;

	tmp = NULL;
	if ((*first_node) == NULL)
	{
		*first_node = new;
		return (new);
	}
	tmp = *first_node;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

void	ft_free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

t_points	*coordinates(t_points *head, int fd)
{
	int			y;
	char		*str;
	char		**split_str;
	int			x;
	t_points	*node;

	str = NULL;
	node = NULL;
	str = get_next_line(fd);
	y = 0;
	while (str)
	{
		split_str = ft_split(str, ' ');
		free(str);
		x = 0;
		while (split_str[x])
		{
			node = ft_lstadd_node(&head, ft_new_node(split_str[x], x, y));
			x++;
		}
		ft_free_split(split_str);
		str = get_next_line(fd);
		node->eol = 1;
		y++;
	}
	if (str)
		free(str);
	node->next = NULL;
	return (head);
}
