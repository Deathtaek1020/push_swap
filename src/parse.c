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

static int	add_token(const char *tok, t_node **a)
{
	long	val;
	
	if (!strict_atol(tok, &val))
		return (0);
	if (val < (long)INT_MIN || val > (long)INT_MAX)
		return (0);
	if (has_duplicate(*a, (int)val))
		return (0);
	{
		t_node	*n;

		n = node_new((int)val);
		if (!n)
			return (0);
		stack_add_back(a, n);
	}
	return (1);
}

static int	process_arg(char *arg, t_node **a)
{
	char	**toks;
	int	i;

	toks = ft_split(arg, ' ');
	if (!toks)
		return (0);
	i = 0;
	while (toks[i])
	{
		if (!add_token(toks[i], a))
		{
			free_tokens(toks);
			return (0);
		}
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