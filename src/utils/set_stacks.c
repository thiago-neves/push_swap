#include "../../inc/push_swap.h"

static void set_stack_a(char **numbers, t_stack *stack)
{
	long number;
	int i;

	i = 0;
	while (i < stack->length)
	{
		number = ft_atoi(numbers[i + 1]);
		if (number > MAX_INT_NUM || number < MIN_INT_NUM)
			close_program();
		verify_duplication(stack, number, i);
		stack->b.index[i] = number;
		i++;
	}
	fill_array_a(stack);
	reset_array(&stack->b, stack->length);
}

void set_stacks(t_stack *stack, char **numbers)
{
	stack->a.index = malloc(sizeof(int) * stack->length);
	stack->b.index = malloc(sizeof(int) * stack->length);
	stack->a.length = stack->length;
	stack->b.length = 0;
	if (stack->a.index == NULL || stack->b.index == NULL)
		close_program();
	length_verification(stack->length);
	integer_verification(numbers);
	set_stack_a(numbers, stack);
}