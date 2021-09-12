/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 08:36:18 by skoh              #+#    #+#             */
/*   Updated: 2021/09/12 12:06:29 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_swap(void *a, void *b, size_t size)
{
	char	*x;
	char	*y;
	char	*z;

	x = (char *)a;
	y = (char *)b;
	z = (char *)malloc(size);
	if (!z)
		return ;
	ft_memcpy(z, x, size);
	ft_memcpy(x, y, size);
	ft_memcpy(y, z, size);
	free(z);
}
