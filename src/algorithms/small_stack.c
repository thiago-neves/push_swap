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

void sort_four_numbers(t_stack *stack, t_array *a)
{
	push_b(stack);
	if (!is_sorted(a))
		sort_three_numbers(stack, &stack->a);
	push_a(stack);
	if (a->index[0] > a->index[1] && a->index[0] < a->index[2])
		swap_a(stack);
	else if (a->index[0] > a->index[2] && a->index[0] < a->index[3])
	{
		swap_a(stack);
		rotate_a(stack);
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (a->index[0] > a->index[3])
		rotate_a(stack);
}

void sort_five_numbers(t_stack *stack, t_array *a)
{
	push_b(stack);
	if (!is_sorted(a))
		sort_four_numbers(stack, &stack->a);
	push_a(stack);
	if (a->index[0] > a->index[1] && a->index[0] < a->index[2])
		swap_a(stack);
	else if (a->index[0] > a->index[2] && a->index[0] < a->index[3])
	{
		swap_a(stack);
		rotate_a(stack);
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (a->index[0] > a->index[3] && a->index[0] < a->index[4])
	{
		reverse_rotate_a(stack);
		swap_a(stack);
		rotate_a(stack);
		rotate_a(stack);
	}
	else if (a->index[0] > a->index[4])
		rotate_a(stack);
}

int small_stack(t_stack *stack)
{
	if (!is_sorted(&stack->a))
	{
		if (stack->a.length == 2)
			swap_a(stack);
		else if (stack->a.length == 3)
			sort_three_numbers(stack, &stack->a);
		else if (stack->a.length == 4)
			sort_four_numbers(stack, &stack->a);
		else if (stack->a.length == 5)
			sort_five_numbers(stack, &stack->a);
	}
	return (0);
}