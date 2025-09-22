#include "push_swap.h"

static size_t	word_count(const char *s, char c)
{
	size_t	i;
	size_t	n;

	if (!s)
		return (0);
	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			{
			n++;
			while (s[i] && s[i] != c)
				i++;
			}
	}
	return (n);
}

static char	*word_dup(const char *s, size_t st, size_t en)
{
	char	*out;
	size_t	i;

	out = (char *)malloc(en - st + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (st < en)
		out[i++] = s[st++];
	out[i] = '\0';
	return (out);
}

static void	free_all(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	st;
	size_t	nw;
	char	**out;

	nw = word_count(s, c);
	out = (char **)ft_calloc(nw + 1, sizeof(char *));
	if (!out)
		return (NULL);
	i = 0;
	st = 0;
	nw = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		st = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > st)
		{
			out[nw] = word_dup(s, st, i);
			if (!out[nw++])
				return (free_all(out, nw - 1), NULL);
		}
	}
	out[nw] = NULL;
	return (out);
}