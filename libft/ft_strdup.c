/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:07:19 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:07:20 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** strdup -- save a copy of a string
**
** strdup() function allocates sufficient memory for a copy of the string s1,
** does the copy, and returns a pointer to it.  The pointer may subsequently be
** used as an argument to the function free(3).
**
** If insufficient memory is available, NULL is returned and errno is set to
** ENOMEM.
*/

char	*ft_strdup(const char *s1)
{
	void	*dst;
	size_t	dst_size;

	dst_size = ft_strlen(s1) + 1;
	dst = malloc(dst_size);
	if (dst)
		ft_memcpy(dst, s1, dst_size);
	return (dst);
}
