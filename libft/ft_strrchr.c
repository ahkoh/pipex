/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Koh <skoh@student.42kl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:53:10 by Koh               #+#    #+#             */
/*   Updated: 2021/05/25 09:15:11 by Koh              ###   ########.kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strchr, strrchr -- locate character in string
**
** The strchr() function locates the first occurrence of c(converted to a char)
** in the string pointed to by s.
** The terminating null character is considered to be part of the string;
** therefore if cis `\0', the functions locate the terminating `\0'.
** The strrchr() function is identical to strchr(),
** except it locates the last occurrence of c.
**
** The function strrchr() return a pointer to the located character,
** or NULL if the character does not appear in the string.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*r;

	c = (char)c;
	r = 0;
	while (*s)
	{
		if (*s == c)
			r = (char *)s;
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (r);
}
