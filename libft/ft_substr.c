/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:08:07 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:08:08 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Allocates and returns a substring from the string 's'.
** The substring begins at index 'start' and is of maximum size 'len'
**
** Return empty string if index 'start' beyond string 's' or len is 0;
** or NULL if the allocation fails.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	dst_len;

	if (len)
		dst_len = ft_strlen(s);
	else
		dst_len = 0;
	if (dst_len <= start)
		return (ft_strdup(""));
	dst_len -= start;
	if (dst_len > len)
		dst_len = len;
	dst = (char *)malloc(dst_len + 1);
	if (dst)
		ft_strlcpy(dst, s + start, dst_len + 1);
	return (dst);
}

// char	*ft_substr(const char *s, unsigned int start, unsigned int len)
// {
// 	char		*dest;
// 	const int	size = len - start;

// 	dest = malloc(size);
// 	if (dest)
// 	{
// 		ft_memccpy(dest, s, '\0', size);
// 		dest[size - 1] = '\0';
// 	}
// 	return (dest);
// }
