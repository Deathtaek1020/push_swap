#include "push_swap.h"

static void	sort_int_array(int *arr, int n)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[i])
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
			j++;
		}
		i++;
	}
}

void	index_values(t_node *a)
{
	int	n;
	int	i;
	int	*arr;
	t_node	*cur;

	n = stack_size(a);
	if (n <= 0)
		return ;
	arr = (int *)ft_calloc(n, sizeof(int));
	if (!arr)
		return ;
	cur = a;
	i = 0;
	while (cur)
	{
		arr[i++] = cur->val;
		cur = cur->next;
	}
	sort_int_array(arr, n);
	cur = a;
	while (cur)
	{
		i = 0;
		while (i < n && arr[i] != cur->val)
			i++;
		cur->idx = i;
		cur = cur->next;
	}
	free(arr);
}

static int	max_bits_from_stack(t_node *a)
{
	int	max;
	int	bits;
	t_node	*cur;

	max = 0;
	cur = a;
	while (cur)
	{
		if (cur->idx > max)
			max = cur->idx;
		cur = cur->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	if (bits == 0)
		bits = 1;
	return (bits);
}

void	radix_sort(t_node **a, t_node **b)
{
	int	bits;
	int	sz;
	int	i;
	int	j;

	if (!a || !*a)
		return ;
	bits = max_bits_from_stack(*a);
	sz = stack_size(*a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < sz)
		{
			if (((*a)->idx >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}