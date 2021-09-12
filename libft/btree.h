#ifndef BTREE_H
# define BTREE_H

typedef struct s_btree	t_btree;

struct s_btree
{
	void	*data;
	t_btree	*left;
	t_btree	*right;
};

t_btree	*btree_add(t_btree *btree, void *data, int (*cmp)());
void	btree_apply_infix(
			t_btree *btree, void(*f)(void *data, void *param), void *param);
void	btree_free(t_btree *btree, void(*f)(void *));

#endif
