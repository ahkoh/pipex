/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:07:31 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:07:32 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Allocates and returns a new string, which is the result of the concatenation
** of 's1' and 's2'.
**
** Returns the new string or NULL if the allocation fails.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len1;
	size_t	len2;

	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	dst = (char *)malloc(len1 + len2 + 1);
	if (dst)
	{
		ft_memcpy(dst, s1, len1);
		ft_memcpy(dst + len1, s2, len2);
		dst[len1 + len2] = 0;
	}
	return (dst);
}
