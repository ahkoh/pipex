/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_enqueue_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:04:16 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:04:20 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// FIFO
int	ft_list_enqueue(t_list **head, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (new)
		ft_lstadd_back(head, new);
	return (new != NULL);
}
