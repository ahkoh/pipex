/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:06:03 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:06:04 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include "libft.h"
#include <unistd.h>

static int	ft_putbase_recursive(
	unsigned long nbr, const char *base, size_t max, int fd)
{
	int	count;

	count = 0;
	if (nbr >= max)
		count = ft_putbase_recursive(nbr / max, base, max, fd);
	return (write(fd, base + (nbr % max), 1) + count);
}

int	ft_putbase(unsigned long nbr, const char *base, int fd)
{
	return (ft_putbase_recursive(nbr, base, ft_strlen(base), fd));
}

static int	ft_putunbr(unsigned long nbr, int fd)
{
	return (ft_putbase(nbr, "0123456789", fd));
}

int	ft_putnbr(long nbr, int fd)
{
	if (nbr < 0)
	{
		write(fd, "-", 1);
		return (ft_putunbr(-nbr, fd) + 1);
	}
	return (ft_putunbr(nbr, fd));
}
