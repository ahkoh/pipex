/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Koh <skoh@student.42kl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 02:34:38 by Koh               #+#    #+#             */
/*   Updated: 2021/05/24 22:35:22 by Koh              ###   ########.kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** The calloc() function contiguously allocates enough space for countobjects
** that are sizebytes of memory each and returns a pointer to the allocated
** memory. The allocated memory is filled with bytes of value zero.
**
** If successful, calloc() function return a pointer to allocated memory.
** If there is an error, it returns a NULL pointer.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (p)
		ft_memset(p, 0, count * size);
	return (p);
}
