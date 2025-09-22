#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/* Stack node */
typedef struct s_node
{
	int			val;
	int			idx; /* compressed index [0..n-1] */
	struct s_node	*next;
} 	 t_node;

/* mini_libft */
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		strict_atol(const char *s, long *out);
void	ps_putstr_fd(const char *s, int fd);
char	**ft_split(char const *s, char c);

/* stack */
t_node	*node_new(int v);
void	stack_add_back(t_node **st, t_node *n);
int		stack_size(t_node *st);
int		stack_is_sorted_vals(t_node *st);
void	free_stack(t_node **st);

/* ops (only the ones we use) */
void	sa(t_node **a);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);

/* parsing */
int		parse_input(int ac, char **av, t_node **a);

/* radix */
void	index_values(t_node *a);
void	radix_sort(t_node **a, t_node **b);

#endif
