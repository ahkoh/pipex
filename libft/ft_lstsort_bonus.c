/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Koh <skoh@student.42kl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:30:19 by Koh               #+#    #+#             */
/*   Updated: 2021/05/24 06:55:27 by Koh              ###   ########.kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list *lst, int (*cmp)(void *, void *))
{
	size_t	size;
	int		i;
	t_list	*p;
	void	*swp;

	size = ft_lstsize(lst);
	while (size > 1)
	{
		i = --size;
		p = lst;
		while (i-- && p->next)
		{
			if ((*cmp)(p->content, p->next->content) > 0)
			{
				swp = p->content;
				p->content = p->next->content;
				p->next->content = swp;
			}
			p = p->next;
		}
	}
}
