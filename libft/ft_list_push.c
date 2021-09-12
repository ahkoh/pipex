/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:05:06 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:05:06 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// LIFO
int	ft_list_push(t_list **head, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (new)
		ft_lstadd_front(head, new);
	return (new != NULL);
}
