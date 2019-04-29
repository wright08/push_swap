#include "push_swap.h"
#include <stdio.h>

void	solve(int *a, int n)
{
	t_stack a_stack;
	t_stack b_stack;

	init(&a_stack, a, n);
	init(&b_stack, ft_memalloc(n * sizeof(int)), -1);
	simple_sort(&a_stack, &b_stack);
}

int		main(int argc, char **argv)
{
	int		*a;
	int		i;

	if (argc == 1)
		return (0);
	a = ft_memalloc((argc - 1) * sizeof(int));
	i = 0;
	while (++i < argc)
	{
		if (valid_int(argv[i]))
			a[argc - i - 1] = ft_atoi(argv[i]);
		else
			break ;
	}
	if (i < argc || has_duplicate(a, argc - 1))
		ft_putstr_fd("Error\n", 2);
	else
		solve(a, argc - 1);
	free(a);
	return (0);
}

// Quick sort
// Pick a pivot, put everything lower than the pivot on one side, put everything
// else on the other, swap the pivot, recur into the left and right sides

// I suppose the most awkward part of this is determining what is to the right
// and left considering its a fucking circle