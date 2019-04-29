#include "push_swap.h"

// We could
// 1. Take the value underneath the top of the stack
// 2. Take the value at the bottom of the stack
// 3. Take the value at the top of the stack
void	setup(t_stack *a, t_stack *b)
{
	int min;

	while (a->top)
	{
		min = a->s[a->top];
		if (a->top > 0 && a->s[a->top - 1] < min)
			min = a->s[a->top - 1];
		if (a->s[0] < min)
			min = a->s[0];
		if (a->top > 0 && min == a->s[a->top - 1])
			swap(a);
		else if (min == a->s[0])
			retate(a);
		push(b, a);
	}
}



void	simple_sort(t_stack *a, t_stack *b)
{
	setup(a, b);
}