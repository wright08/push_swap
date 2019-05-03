#include "push_swap.h"
#include "ft_printf.h"

void	init(t_stack *stack, int *s, int top, char name)
{
	stack->s = s;
	stack->top = top;
	stack->name = name;
}

void	swap(t_stack *stack)
{
	int	tmp;
	if (stack->top < 1)
		return ;
	tmp = stack->s[stack->top];
	stack->s[stack->top] = stack->s[stack->top - 1];
	stack->s[stack->top - 1] = tmp;
	if (stack->name)
		ft_printf("s%c\n", stack->name);
}

void	push(t_stack *dst, t_stack *src)
{
	if (src->top < 0)
		return ;
	dst->s[++(dst->top)] = src->s[(src->top)--];
	if (dst->name)
		ft_printf("p%c\n", dst->name);
}

void	rotate(t_stack *stack)
{
	int	tmp;

	if (stack->top < 1)
		return ;
	tmp = stack->s[stack->top];
	ft_memmove(stack->s + 1, stack->s, stack->top * sizeof(int));
	stack->s[0] = tmp;
	if (stack->name)
		ft_printf("r%c\n", stack->name);
}

void	retate(t_stack *stack)
{
	int	tmp;

	if (stack->top < 1)
		return ;
	tmp = stack->s[0];
	ft_memmove(stack->s, stack->s + 1, stack->top * sizeof(int));
	stack->s[stack->top] = tmp;
	if (stack->name)
		ft_printf("rr%c\n", stack->name);
}