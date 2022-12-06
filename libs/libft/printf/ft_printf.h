/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:47:50 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/18 19:21:53 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# define BASE_10 "0123456789"
# define BASE_HEX_UP "0123456789ABCDEF"
# define BASE_HEX_LW "0123456789abcdef"

int	ft_printf(const char *format, ...);
int	ft_putchar_v(char c);
int	ft_putstr_v(char *s);
int	ft_putnbase(long long nb, char *base, int reset);
int	ft_print_addr(unsigned long addr);

#endif
