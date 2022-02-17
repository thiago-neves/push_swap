#include "../../inc/push_swap.h"

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
	printf("rra\n");
}

void reverse_rotate_b(t_stack *stack)
{
	reverse_rotate(&stack->b);
	printf("rrb\n");
}

void reverse_rotate_s(t_stack *stack)
{
	reverse_rotate(&stack->a);
	reverse_rotate(&stack->b);
	printf("rrr\nnt main(int array_length, char **numbers)
{
	t_stack stack;

	stack.length = array_length - 1;
	set_stacks(&stack, numbers);
	if (stack.length <= 5)
		small_stack(&stack);
	else
		big_stack(&stack);
	int i = 0;
	printf("\na\tb\n");
	while (i < stack.length)
	{
		printf("%d\t%d\n", stack.a.index[i], stack.b.index[i]);
		i++;
	}
	return (0);
}
");
}