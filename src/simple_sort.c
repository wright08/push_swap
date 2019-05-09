#include "push_swap.h"

/*
**	1 3 2 -> rra
**	2 3 1 -> rra, sa
**	2 1 3 -> ra
**	3 1 2 -> sa
**	1 2 3 -> sa, rra
*/
void	sort_3(t_stack *stack_a, t_stack *stack_b)
{
	const int	a = stack_a->s[stack_a->top];
	const int	b = stack_a->s[stack_a->top - 1];
	const int	c = stack_a->s[stack_a->top - 2];

	(void)stack_b;
	if (a < b && b > c)
	{
		retate(stack_a);
		if (c > a)
			swap(stack_a);
	}
	else if (a > b && b < c && c < a)
		rotate(stack_a);
	else if (a > b && b < c) 
		swap(stack_a);
	else if (a > b && b > c)
	{
		swap(stack_a);
		retate(stack_a);
	}
}


void	sort_5(t_stack *a, t_stack *b)
{
	int		rotations;
	int		end;
	int		special;

	push(b, a);
	push(b, a);
	sort_3(a, b);
	if (b->s[0] < b->s[1])
		swap(b);
	rotations = 0;
	special = 0;
	if (b->s[1] > a->s[0])
		special = 2;
	else if (b->s[0] > a->s[0])
		special = 1;
	end = a->s[0];
	while (a->s[a->top] != end)
	{
		if (b->s[b->top] < a->s[a->top])
			push(a, b);
		else
		{
			rotate(a);
			rotations++;
		}
	}
	while (rotations++ < 5)
		rotate(a);
}

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
	if (a->top == 2)
		sort_3(a, b);
	else if (a->top == 4)
		sort_5(a, b);
	else
		small_sort(a, b, a->top + 1);
}