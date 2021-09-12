/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <skoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:02:45 by skoh              #+#    #+#             */
/*   Updated: 2021/09/06 14:02:46 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <stdlib.h>

t_btree	*btree_add(t_btree *btree, void *data, int (*compare)())
{
	if (btree)
	{
		if ((*compare)(data, btree->data) <= 0)
			btree->left = btree_add(btree->left, data, compare);
		else
			btree->right = btree_add(btree->right, data, compare);
	}
	else
	{
		btree = malloc(sizeof(t_btree));
		btree->data = data;
		btree->left = (btree->right = NULL);
	}
	return (btree);
}

// apply function in sorted-order, eg print sorted list
void	btree_apply_infix(
	t_btree *btree,
	void(*f)(void *data, void *param),
	void *param)
{
	if (btree)
	{
		btree_apply_infix(btree->left, f, param);
		(*f)(btree->data, param);
		btree_apply_infix(btree->right, f, param);
	}
}

void	btree_free(t_btree *btree, void(*f)(void*))
{
	if (!btree)
		return ;
	btree_free(btree->left, f);
	btree_free(btree->right, f);
	if (f)
		(*f)(btree->data);
	free(btree);
}
