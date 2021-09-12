/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Koh <skoh@student.42kl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 05:13:00 by Koh               #+#    #+#             */
/*   Updated: 2021/05/20 21:14:53 by Koh              ###   ########.kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a = (const unsigned char *)s1;
	const unsigned char	*b = (const unsigned char *)s2;

	while (n && *a == *b)
	{
		a++;
		b++;
		n--;
	}
	if (n)
		return (*a - *b);
	return (0);
}
