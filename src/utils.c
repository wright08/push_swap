#include "push_swap.h"

int     valid_int(char *str)
{
	int		len;
	char	neg;

	if ((neg = (*str == '-')))
		str++;
	len = -1;
	while (str[++len])
		if(!ft_isdigit(str[len]))
			return (0);
	if (len > 10)
		return (0);
	else if (len < 10)
		return (1);
	else
	{
		if (neg)
			return (ft_strcmp(str, "2147483648") <= 0);
		else
			return (ft_strcmp(str, "2147483647") <= 0);
	}
}

int		has_duplicate(int *a, int n)
{
	int i;
	int	j;

	if (n == 1)
		return (0);
	i = -1;
	while (++i < n - 1)
	{
		j = i;
		while (++j < n)
			if (a[i] == a[j])
				return (1);
	}
	return (0);
}
