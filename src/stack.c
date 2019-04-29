#include "push_swap.h"

void	init(t_stack *stack, int *s, int top)
{
	stack->s = s;
	stack->top = top;
}

void	swap(t_stack *stack)
{
	int	tmp;
	if (stack->top < 1)
		return ;
	tmp = stack->s[stack->top];
	stack->s[stack->top] = stack->s[stack->top - 1];
	stack->s[stack->top - 1] = tmp;
}

void	push(t_stack *dst, t_stack *src)
{
	if (src->top < 0)
		return ;
	dst->s[++(dst->top)] = src->s[(src->top)--];
}

void	rotate(t_stack *stack)
{
	int	tmp;

	if (stack->top < 1)
		return ;
	tmp = stack->s[stack->top];
	ft_memmove(stack->s + 1, stack->s, stack->top * sizeof(int));
	stack->s[0] = tmp;
}

void	retate(t_stack *stack)
{
	int	tmp;

	if (stack->top < 1)
		return ;
	tmp = stack->s[0];
	ft_memmove(stack->s, stack->s + 1, stack->top * sizeof(int));
	stack->s[stack->top] = tmp;
}