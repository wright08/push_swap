#include "push_swap.h"

int		*get_smallest_nums(t_stack *a, int total, int small)
{
	int		cur;
	int		*smallest_n_arr;

	small_n_arr = malloc(sizeof(int) * small);
	cur = a->s[a->top];
	while (small--)
	{

	}
}

// Split n elements on to a and b stack; put smallest n / 2 elements on b stack,
// sort the a stack in increasing order, overlap as many commands as possible to sort b
// stack in reverse order to be popped onto a
void    small_sort(t_stack *a, t_stack *b, int n)
{
	int     smallest_n;
	int     *small_n_arr;

	smallest_n = n / 2;
	small_n_arr = get_smallest_nums(a, n, smallest_n);
}