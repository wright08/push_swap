#include "push_swap.h"

int     valid_int(char *str)
{
	int		len;

	len = (*str == '-') - 1;
	while (str[++len])
		if(!ft_isdigit(str[len]))
			return (0);
	if (len > 10)
		return (0);
	else if (len < 10)
		return (1);
	else
	{
		if (*str == '-')
			return (ft_strcmp(str, "-2147483648") <= 0);
		else
			return (ft_strcmp(str, "2147483647") <= 0);
	}
}

int		main(int argc, char **argv)
{
}