#include "../../inc/push_swap.h"

int is_sorted(t_array *array)
{
	int	i;

	i = 1;
	while (i < array->length)
	{
		if (array->index[i - 1] > array->index[i])
			return (0);
		i++;
	}
	return (1);
}

void sort_three_numbers(t_stack *stack, t_array *a)
{
	if (a->index[0] > a->index[1] && a->index[0] < a->index[2])
		swap_a(stack);
	else if (a->index[0] > a->index[1] && a->index[1] < a->index[2])
		rotate_a(stack);
	else if (a->index[0] < a->index[1] && a->index[0] > a->index[2])
		reverse_rotate_a(stack);
	else if (a->index[0] < a->index[1] && a->index[0] < a->index[2])
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (a->index[0] > a->index[1] && a->index[1] > a->index[2])
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
}

int small_stack(t_stack *stack)
{
	if (stack->a.length == 2 && !is_sorted(&stack->a))
		swap_a(stack);
	else if (stack->a.length == 3 && !is_sorted(&stack->a))
		sort_three_numbers(stack, &stack->a);
	return (0);
}