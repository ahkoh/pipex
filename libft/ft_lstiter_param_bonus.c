/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Koh <skoh@student.42kl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 00:23:05 by Koh               #+#    #+#             */
/*   Updated: 2021/05/21 01:10:33 by Koh              ###   ########.kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter_param(
	t_list *lst, void (*f)(void *content, int index, void *param), void *param)
{
	int	i;

	i = 0;
	while (lst)
	{
		(*f)(lst->content, i++, param);
		lst = lst->next;
	}
}
