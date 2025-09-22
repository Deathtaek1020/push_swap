#include "push_swap.h"

static void	free_tokens(char **toks)
{
	int	i;

	if (!toks)
		return ;
	i = 0;
	while (toks[i])
	{
		free(toks[i]);
		i++;
	}
	free(toks);
}

static int	has_duplicate(t_node *a, int v)
{
	while (a)
	{
		if (a->val == v)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	process_arg(char *arg, t_node **a)
{
	char	**toks;
	int	i;
	long	val;
	t_node	*n;

	toks = ft_split(arg, ' ');
	if (!toks)
		return (0);
	i = 0;
	while (toks[i])
	{
		if (!strict_atol(toks[i], &val))
			return (free_tokens(toks), 0);
		if (val < (long)INT_MIN || val > (long)INT_MAX)
			return (free_tokens(toks), 0);
		if (has_duplicate(*a, (int)val))
			return (free_tokens(toks), 0);
		n = node_new((int)val);
		if (!n)
			return (free_tokens(toks), 0);
		stack_add_back(a, n);
		i++;
	}
	free_tokens(toks);
	return (1);
}

int	parse_input(int ac, char **av, t_node **a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!process_arg(av[i], a))
			return (0);
		i++;
	}
	return (1);
}