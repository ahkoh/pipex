/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Koh <skoh@student.42kl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 02:42:00 by Koh               #+#    #+#             */
/*   Updated: 2021/05/20 02:57:28 by Koh              ###   ########.kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

#if	TEST

int	main(void)
{
	ft_putnbr_fd(ft_strncmp("", "", 3), 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(ft_strncmp("c", "abc", 0), 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(ft_strncmp("bcda", "bcga", 3), 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(ft_strncmp("bcda", "bc", 30), 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(ft_strncmp("bcda", "bcc", 2), 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

#endif
