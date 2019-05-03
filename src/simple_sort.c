#include "push_swap.h"

// We could
// 1. Take the value underneath the top of the stack
// 2. Take the value at the bottom of the stack
// 3. Take the value at the top of the stack
void	setup(t_stack *a, t_stack *b)
{
	int min;

	while (a->top >= 0)
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

void	get_next_val(t_stack *a, t_stack *b)
{
	int max;
	int	forwards;
	int i;

	max = 0;
	i = -1;
	while (++i <= b->top)
		if (b->s[i] > b->s[max])
			max = i;
	forwards = (max >= (b->top / 2));
	max = b->s[max];
	if (forwards)
		while (b->s[b->top] != max)
			rotate(b);
	else
		while (b->s[b->top] != max)
			retate(b);
	push(a, b);
}

void	simple_sort(t_stack *a, t_stack *b)
{
	setup(a, b);
	while (b->top >= 0)
		get_next_val(a, b);
}

// Determine if the largest stack is closer by r or rr, then do that until its at the top of the stack
// push it onto the stack
// Do until b is empty


// 1 3 4 2 5
// 0 1 2 3 4

// 5 4 3 2 1
// 5 2 3 4 1