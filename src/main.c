#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_input(ac, av, &a))
	{
		ps_putstr_fd("Error\n", 2);
		free_stack(&a);
		return (1);
	}
	if (stack_is_sorted_vals(a))
	{
		free_stack(&a);
		return (0);
	}
	index_values(a);
	if (stack_size(a) == 2 && !stack_is_sorted_vals(a))
		sa(&a);
	else
		radix_sort(&a, &b);
	free_stack(&a);
	/* b doit être vide */
	return (0);
}
