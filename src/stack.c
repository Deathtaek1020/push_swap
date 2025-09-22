#include "push_swap.h"

t_node	*node_new(int v)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->val = v;
	n->idx = -1;
	n->next = NULL;
	return (n);
}

void	stack_add_back(t_node **st, t_node *n)
{
	t_node	*cur;

	if (!st || !n)
		return ;
	if (!*st)
	{
		*st = n;
		return ;
	}
	cur = *st;
	while (cur->next)
		cur = cur->next;
	cur->next = n;
}

int	stack_size(t_node *st)
{
	int	i;

	i = 0;
	while (st)
	{
		i++;
		st = st->next;
	}
	return (i);
}

int	stack_is_sorted_vals(t_node *st)
{
	if (!st)
		return (1);
	while (st->next)
	{
		if (st->val > st->next->val)
			return (0);
		st = st->next;
	}
	return (1);
}

void	free_stack(t_node **st)
{
	t_node	*tmp;

	if (!st)
		return ;
	while (*st)
	{
		tmp = (*st)->next;
		free(*st);
		*st = tmp;
	}
}
