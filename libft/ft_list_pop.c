/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:05:00 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:05:02 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// Stack/LIFO with push or Queue/FIFO with enqueue
void	*ft_list_pop(t_list **head)
{
	void	*content;
	t_list	*node;

	if (!*head)
		return (NULL);
	content = (*head)->content;
	node = *head;
	*head = (*head)->next;
	free(node);
	return (content);
}
