/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:05:37 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:05:38 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** memchr -- locate byte in byte string
**
** The memchr() function locates the first occurrence of c (converted to an
** unsigned char) in string s.
**
** The memchr() function returns a pointer to the byte located,
** or NULL if no such byte exists within n bytes.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p = (const unsigned char *)s;

	c = (unsigned char)c;
	while (n && *p != c)
	{
		p++;
		n--;
	}
	if (n)
		return ((void *)p);
	else
		return (0);
}
