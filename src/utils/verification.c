#include "../inc/push_swap.h"

void verify_duplication(t_stack *stack, int number)
{
	int i;

	i = 0;
	if (number == 0 && stack->has_zero)
		close_program();
	while (i < stack->array_length)
	{
		if (stack->a.index[i] == number && number != 0)
			close_program();
		else if (number == 0)
		{
			stack->has_zero = 1;
			i = stack->array_length;
		}
		i++;
	}
}

void length_verification(int array_length)
{
	if (array_length == 0)
		close_program_with_tip();
}

void integer_verification(char **numbers)
{
	unsigned int i;
	unsigned int j;

	i = 1;
	while (numbers[i])
	{
		j = 0;
		while (numbers[i][j])
		{
			if (!ft_isdigit(numbers[i][j]) && \
				numbers[i][j] != '-' && numbers[i][j] != '+')
				close_program();
			j++;
		}
		i++;
	}
}
