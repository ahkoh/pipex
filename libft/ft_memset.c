/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Koh <skoh@student.42kl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 02:57:54 by Koh               #+#    #+#             */
/*   Updated: 2021/05/25 09:09:10 by Koh              ###   ########.kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** memset -- fill a byte string with a byte value
**
** The memset() function writes len bytes of value c (converted to an unsigned
** char) to the string b.
**
** The memset() function returns its first argument.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst;

	dst = (unsigned char *)b;
	c = (unsigned char)c;
	while (len--)
		dst[len] = c;
	return (b);
}
