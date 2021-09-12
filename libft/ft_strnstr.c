/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Koh <skoh@student.42kl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 06:57:31 by Koh               #+#    #+#             */
/*   Updated: 2021/05/25 10:39:06 by Koh              ###   ########.kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strnstr() function locates the first occurrence of the null-terminated
** string needle in the string haystack, where not more than len characters are
** searched.  Characters that appear after a `\0' character are not searched. 
**
** If needle is an empty string, haystack is returned; if needle occurs nowhere
** in haystack, NULL is returned; otherwise a pointer to the first character of
** the first occurrence of needle is returned.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	while (len-- && *haystack)
	{
		if (*haystack == *needle)
		{
			i = 1;
			while (i <= len && needle[i])
			{
				if (haystack[i] == 0)
					return (0);
				if (haystack[i] != needle[i])
					break ;
				i++;
			}
			if (needle[i] == 0)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (0);
}
