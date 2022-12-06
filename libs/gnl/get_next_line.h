/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:53:20 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/03 16:21:58 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

/*****************************
 *-- Check BUF_SIZE define --*
 ****************************/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/*****************************
 *-- Utils + main function --*
 ****************************/

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *line, char *buf);
void	ft_substr_gnl(char *buf);

#endif
