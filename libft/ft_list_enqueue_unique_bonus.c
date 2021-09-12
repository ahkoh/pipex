/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_enqueue_unique_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:04:44 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:04:45 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// FIFO
int	ft_list_enqueue_unique(
	t_list **head, void *content, int (*cmp)(void *new, void *cur))
{
	t_list	*new;
	t_list	*lst;

	new = ft_lstnew(content);
	if (!new)
		return (0);
	if (!*head)
		return (!!(*head = new));
	lst = *head;
	while (1)
	{
		if ((*cmp)(new->content, lst->content) == 0)
		{
			free(new);
			return (0);
		}
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	lst->next = new;
	return (1);
}
