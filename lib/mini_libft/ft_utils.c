#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	size_t	i;
	unsigned char	*p;

	total = count * size;
	p = (unsigned char *)malloc(total);
	if (!p)
		return (NULL);
	i = 0;
	while (i < total)
		p[i++] = 0;
	return ((void *)p);
}

void	ps_putstr_fd(const char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

int	strict_atol(const char *s, long *out)
{
	int		i;
	long		sign;
	long		res;

	if (!s || !*s)
		return (0);
	i = 0;
	sign = 1;
	res = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit((unsigned char)s[i]))
			return (0);
		res = res * 10 + (s[i] - '0');
		if (sign == 1 && res > (long)INT_MAX)
			return (0);
		if (sign == -1 && -res < (long)INT_MIN)
			return (0);
		i++;
	}
	*out = res * sign;
	return (1);
}