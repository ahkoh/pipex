/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitfree_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:06:59 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:07:00 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// char	**arr = ft_split("1 2 3", ' ');
// ft_splitfree(&arr);
void	ft_splitfree(char ***tab)
{
	int	i;

	if (*tab)
	{
		i = 0;
		while ((*tab)[i])
			free((*tab)[i++]);
		free(*tab);
		*tab = NULL;
	}
}
