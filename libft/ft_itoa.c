/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Koh <skoh@student.42kl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:21:41 by Koh               #+#    #+#             */
/*   Updated: 2021/05/25 03:45:21 by Koh              ###   ########.kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	numlen(int n)
{
	int	i;

	if (!n)
		return (1);
	i = n < 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*s;
	int				len;
	unsigned int	u;

	len = numlen(n) + 1;
	s = (char *)malloc(sizeof(char) * len);
	if (s)
	{
		s[--len] = 0;
		if (n < 0)
		{
			s[0] = '-';
			u = -n;
		}
		else
			u = n;
		while (1)
		{
			s[--len] = '0' + (u % 10);
			u /= 10;
			if (!u)
				break ;
		}
	}
	return (s);
}
