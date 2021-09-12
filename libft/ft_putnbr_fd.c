/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Koh <skoh@student.42kl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:42:56 by Koh               #+#    #+#             */
/*   Updated: 2021/05/23 14:17:22 by Koh              ###   ########.kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		u = -n;
	}
	else
		u = n;
	if (u > 9)
		ft_putnbr_fd(u / 10, fd);
	ft_putchar_fd(u % 10 + '0', fd);
}
