#include "push_swap.h"

/* swap A: swap first two elements of A */
void	sa(t_node **a)
{
	t_node	*x;
	t_node	*y;

	if (!a || !*a || !(*a)->next)
		return ;
	x = *a;
	y = x->next;
	x->next = y->next;
	y->next = x;
	*a = y;
	write(1, "sa\n", 3);
}

/* push A: take first element of B and put it on A */
void	pa(t_node **a, t_node **b)
{
	t_node	*t;

	if (!b || !*b)
		return ;
	t = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = t;
	write(1, "pa\n", 3);
}

/* push B: take first element of A and put it on B */
void	pb(t_node **a, t_node **b)
{
	t_node	*t;

	if (!a || !*a)
		return ;
	t = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = t;
	write(1, "pb\n", 3);
}

/* rotate A: shift up all elements of A by 1, first becomes last */
void	ra(t_node **a)
{
	t_node	*first;
	t_node	*cur;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = first->next;
	first->next = NULL;
	cur = *a;
	while (cur->next)
		cur = cur->next;
	cur->next = first;
	write(1, "ra\n", 3);
}
