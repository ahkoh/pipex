/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Koh <skoh@student.42kl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:57:57 by Koh               #+#    #+#             */
/*   Updated: 2021/05/25 10:25:04 by Koh              ###   ########.kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*d;
	size_t	n;

	if (s)
		n = ft_strlen(s) + 1;
	else
		n = 1;
	d = (char *)malloc(sizeof(char) * n);
	if (d)
	{
		d[--n] = 0;
		n = 0;
		while (s && s[n])
		{
			d[n] = (*f)(n, s[n]);
			n++;
		}
	}
	return (d);
}
