/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Koh <skoh@student.42kl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:38:32 by Koh               #+#    #+#             */
/*   Updated: 2021/05/23 17:51:03 by Koh              ###   ########.kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_found(char c, char const *set)
{
	while (set && *set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (!s1 || !*s1)
		return (ft_strdup(""));
	while (*s1 && set_found(*s1, set))
		s1++;
	len = ft_strlen(s1);
	while (len && set_found(s1[len - 1], set))
		len--;
	return (ft_substr(s1, 0, len));
}
