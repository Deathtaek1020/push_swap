#include "push_swap.h"

static int	get_max_bits(t_node *a)
{
	int	max;
	int	bits;

	max = 0;
	while (a)
	{
		if (a->idx > max)
			max = a->idx;
		a = a->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	if (bits == 0)
		bits = 1;
	return (bits);
}

void	index_values(t_node *a)
{
	t_node	*i;
	t_node	*j;
	int	rank;

i = a;
	while (i)
	{
		rank = 0;
		j = a;
		while (j)
		{
			if (j->val < i->val)
				rank++;
			j = j->next;
		}
		i->idx = rank;
		i = i->next;
	}
}

static void	radix_pass(t_node **a, t_node **b, int bit, int size)
{
	int	i;
	t_node	*cur;

i = 0;
	while (i < size)
	{
		cur = *a;
		if (((cur->idx >> bit) & 1) == 1)
			ra(a);
		else
			pb(a, b);
		i++;
	}
	while (*b)
		pa(a, b);
}

void	radix_sort(t_node **a, t_node **b)
{
	int	size;
	int	bits;
	int	b;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	if (size <= 1 || stack_is_sorted_vals(*a))
		return ;
	bits = get_max_bits(*a);
	b = 0;
	while (b < bits)
	{
		radix_pass(a, b, b, size);
		b++;
	}
}