/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:06:18 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:06:20 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include "libft.h"
#include <unistd.h>

static int	pf_convert_diupxX_pct(t_printf *st)
{
	if (*st->format == 'd' || *st->format == 'i')
		return (st->len += ft_putnbr(va_arg(st->ap, int), st->fd));
	else if (*st->format == 'u')
		return (st->len += ft_putnbr(va_arg(st->ap, unsigned int), st->fd));
	else if (*st->format == 'p')
		return (st->len
			+= write(st->fd, "0x", 2)
			+ ft_putbase(va_arg(st->ap, unsigned long),
				"0123456789abcdef", st->fd));
	else if (*st->format == 'x')
		return (st->len
			+= ft_putbase(va_arg(st->ap, unsigned int),
				"0123456789abcdef", st->fd));
	else if (*st->format == 'X')
		return (st->len
			+= ft_putbase(va_arg(st->ap, unsigned int),
				"0123456789ABCDEF", st->fd));
	return (*st->format == '%' && (st->len += write(st->fd, "%", 1)));
}

// %s: return true even strlen("")==0
static int	pf_convert_csdiupxX_pct(t_printf *st)
{
	char	c;
	char	*s;

	if (*st->format == 'c')
	{
		c = (char)va_arg(st->ap, int);
		return (st->len += write(st->fd, &c, 1));
	}
	else if (*st->format == 's')
	{
		s = va_arg(st->ap, char *);
		if (!s)
			s = "(null)";
		return (1 + (st->len += write(st->fd, s, ft_strlen(s))));
	}
	return (pf_convert_diupxX_pct(st));
}

int	ft_printf(const char *format, ...)
{
	t_printf	st;

	st = (t_printf){.format = format, .len = 0, .fd = STDOUT_FILENO};
	va_start(st.ap, format);
	while (*st.format)
	{
		if (*st.format == '%')
		{
			++st.format;
			if (pf_convert_csdiupxX_pct(&st))
				++st.format;
			else
				st.len += write(st.fd, "%", 1);
		}
		while (*st.format && *st.format != '%')
			st.len += write(st.fd, st.format++, 1);
	}
	va_end(st.ap);
	return (st.len);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	t_printf	st;

	st = (t_printf){.format = format, .len = 0, .fd = fd};
	va_start(st.ap, format);
	while (*st.format)
	{
		if (*st.format == '%')
		{
			++st.format;
			if (pf_convert_csdiupxX_pct(&st))
				++st.format;
			else
				st.len += write(st.fd, "%", 1);
		}
		while (*st.format && *st.format != '%')
			st.len += write(st.fd, st.format++, 1);
	}
	va_end(st.ap);
	return (st.len);
}
