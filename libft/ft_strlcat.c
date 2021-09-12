/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Koh <skoh@student.42kl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 06:28:38 by Koh               #+#    #+#             */
/*   Updated: 2021/05/22 12:13:02 by Koh              ###   ########.kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** if dstsize != 0 & > dstlen then append src and force null-terminated
** null-terminator takes 1B from dstsize, hence dstsize - dstlen - 1 for append
** return (dstlen+srclen) < dstsize if fully copied, otherwise truncated
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	catlen;

	catlen = ft_strlen(dst);
	if (catlen > dstsize)
		catlen = dstsize;
	else if (dstsize && catlen < dstsize)
	{
		dstsize -= catlen;
		dst += catlen;
		while (--dstsize && *src)
		{
			*dst++ = *src++;
			catlen++;
		}
		*dst = 0;
	}
	while (*src++)
		catlen++;
	return (catlen);
}
