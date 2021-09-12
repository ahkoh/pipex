/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:04:55 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:04:56 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// for list with only 1 node (head = tail), must update head pointer
void	*ft_list_pop_last(t_list **head)
{
	t_list	*node;
	void	*content;

	if (!*head || !(*head)->next)
		return (ft_list_pop(head));
	node = *head;
	while (node->next && node->next->next)
		node = node->next;
	content = ft_list_pop(&node->next);
	return (content);
}
