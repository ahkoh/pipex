/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:05:49 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:05:50 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcpy(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s = (const char *)src;

	d = (char *)dst;
	while (len--)
		d[len] = s[len];
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
		return (ft_memrcpy(dst, src, len));
	return (ft_memcpy(dst, src, len));
}
