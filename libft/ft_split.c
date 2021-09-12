/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:06:37 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:06:38 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_split_count_words(const char *s, char sep)
{
	int	count;

	count = 0;
	if (s)
	{
		if (*s)
		{
			if (*s != sep)
				count++;
			s++;
		}
		while (*s)
		{
			if (s[-1] == sep && *s != sep)
				count++;
			s++;
		}
	}
	return (count);
}

static void	*ft_split_undo(char **list, int count)
{
	while (count)
		free(list[--count]);
	free(list);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**list;

	list = (char **)malloc(sizeof(char *) * (ft_split_count_words(s, c) + 1));
	if (!list)
		return (0);
	j = 0;
	while (s && *s)
	{
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (i)
		{
			list[j] = ft_substr(s, 0, i);
			if (!list[j++])
				return (ft_split_undo(list, j));
			s += i;
		}
		else
			s++;
	}
	list[j] = 0;
	return (list);
}
