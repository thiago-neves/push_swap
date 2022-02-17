#include "../../inc/push_swap.h"

static void switch_two(t_array *stack)
{
	int holder;

	holder = stack->index[0];
	stack->index[0] = stack->index[1];
	stack->index[1] = holder;
}

void swap_a(t_stack *stack)
{
	switch_two(&stack->a);
	printf("sa\n");
}

void swap_b(t_stack *stack)
{
	switch_two(&stack->b);
	printf("sb\n");
}

void swap_s(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
	printf("ss\n");
}
