/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:05:56 by skoh              #+#    #+#             */
/*   Updated: 2021/09/07 00:36:25 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H
# include <stdarg.h>

typedef struct s_printf
{
	const char	*format;
	int			fd;
	int			len;
	va_list		ap;
}				t_printf;

int		ft_putbase(unsigned long nbr, const char *base, int fd);
int		ft_putnbr(long nbr, int fd);

#endif
