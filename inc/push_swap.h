#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

struct	s_stack {
	int		*s;
	int		top;
	char	name;
};
typedef struct s_stack	t_stack;

void	simple_sort(t_stack *a, t_stack *b);

int     valid_int(char *str);
int		has_duplicate(int *a, int n);

void	init(t_stack *stack, int *s, int top, char name);
void	swap(t_stack *stack);
void	push(t_stack *dst, t_stack *src);
void	rotate(t_stack *stack);
void	retate(t_stack *stack);

#endif
