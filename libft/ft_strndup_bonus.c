/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:07:55 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:07:56 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** strndup -- save a copy of a string
**
** strndup() function copies at most n characters from the string s1
** always NUL terminating the copied string, and returns a pointer to it.
** The pointer may subsequently be used as an argument to the function free(3).
**
** If insufficient memory is available, NULL is returned and errno is set to
** ENOMEM.
*/

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dst;

	dst = (char *)malloc(n + 1);
	if (dst)
	{
		ft_memcpy(dst, s1, n);
		dst[n] = '\0';
	}
	return (dst);
}
