#include "push_swap.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <stdio.h>

int		is_sorted(int *a, int n)
{
	int i;

	if (n == 1)
		return (1);
	i = -1;
	while (++i < n - 1)
		if (a[i] < a[i + 1])
			return (0);
	return (1);
}

void	print_stacks(t_stack a, t_stack b)
{
	int i;

	printf("a:");
	i = -1;
	while (++i <= a.top)
		printf(" %d", a.s[i]);
	printf("\nb:");
	i = -1;
	while (++i <= b.top)
		printf(" %d", b.s[i]);
	printf("\n");
}

int		check(int *a_stack, int n)
{
	t_stack	a;
	t_stack b;
	char	*line;
	int		moves;

	init(&a, a_stack, n - 1);
	init(&b, ft_memalloc(n * sizeof(int)), -1);
	print_stacks(a, b);
	moves = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strequ(line, "sa"))
			swap(&a);
		else if (ft_strequ(line, "sb"))
			swap(&b);
		else if (ft_strequ(line, "ss"))
		{
			swap(&a);
			swap(&b);
		}
		else if (ft_strequ(line, "pa"))
			push(&a, &b);
		else if (ft_strequ(line, "pb"))
			push(&b, &a);
		else if (ft_strequ(line, "ra"))
			rotate(&a);
		else if (ft_strequ(line, "rb"))
			rotate(&b);
		else if (ft_strequ(line, "rr"))
		{
			rotate(&a);
			rotate(&b);
		}
		else if (ft_strequ(line, "rra"))
			retate(&a);
		else if (ft_strequ(line, "rrb"))
			retate(&b);
		else if (ft_strequ(line, "rrr"))
		{
			retate(&a);
			retate(&b);
		}
		else
		{
			free(b.s);
			return (-1);
		}
		print_stacks(a, b);
		moves++;
	}
	free(b.s);
	printf("%d instructions\n", moves);
	return (is_sorted(a_stack, n));
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
	if (i < argc || has_duplicate(a, argc - 1) || (i = check(a, argc - 1)) == -1)
		ft_putstr_fd("Error\n", 2);
	else
		ft_putstr(i == 0 ? "KO\n" : "OK\n");
	free(a);
	return (0);
}