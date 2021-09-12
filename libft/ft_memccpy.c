/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:05:28 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:05:31 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The memccpy() function copies bytes from string src to string dst.  If the
// character c (as converted to an unsigned char) occurs in the string src, the
// copy stops and a pointer to the byte after the copy of c in the string dst is
// returned.  Otherwise, n bytes are copied, and a NULL pointer is returned.

// The source and destination strings should not overlap, as the behavior is
// undefined.

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*d;
	const char	*s = (const char *)src;

	c = (char)c;
	d = (char *)dst;
	while (n)
	{
		*d = *s;
		if (*d == c)
			break ;
		d++;
		s++;
		n--;
	}
	if (n)
		return ((void *)(d + 1));
	return (0);
}
