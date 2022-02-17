#include "../../inc/push_swap.h"

static void rotate(t_array *array)
{
	int i;
	int holder;

	i = 1;
	holder = array->index[0];
	while (i < array->length - 1)
	{
		array->index[i - 1] = array->index[i];
		i++;
	}
	array->index[i - 1] = array->index[i];
	array->index[i] = holder;
}

void rotate_a(t_stack *stack)
{
	rotate(&stack->a);
	printf("ra\n");
}

void rotate_b(t_stack *stack)
{
	rotate(&stack->b);
	printf("rb\n");
}

void rotate_s(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
	printf("rr\n");
}