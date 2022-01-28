#include "../inc/push_swap.h"

static void reverse_rotate(t_array *array)
{
	int i;
	int holder;
	int new_holder;

	holder = array->index[0];
	array->index[0] = array->index[array->length - 1];
	i = 1;
	while (i < array->length)
	{
		new_holder = array->index[i];
		array->index[i] = holder;
		holder = new_holder;
		i++;
	}
}

void reverse_rotate_a(t_stack *stack)
{
	reverse_rotate(&stack->a);
}

void reverse_rotate_b(t_stack *stack)
{
	reverse_rotate(&stack->b);
}

void reverse_rotate_s(t_stack *stack)
{
	reverse_rotate(&stack->a);
	reverse_rotate(&stack->b);
}