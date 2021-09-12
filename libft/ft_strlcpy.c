/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Koh <skoh@student.42kl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 05:43:12 by Koh               #+#    #+#             */
/*   Updated: 2021/05/25 09:48:44 by Koh              ###   ########.kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copy str with dstsize aware, always null terminated unless 0 dstsize
** null-terminator take 1 byte from dstsize, leaving dstsize-1 for content
** return srclen < dstsize if fully copied, otherwise truncated
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	if (!src)
		return (0);
	srclen = 0;
	if (dstsize)
	{
		while (--dstsize && *src)
		{
			*dst++ = *src++;
			srclen++;
		}
		*dst = 0;
	}
	while (*src++)
		srclen++;
	return (srclen);
}
