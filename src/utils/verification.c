#include "../../inc/push_swap.h"

void verify_duplication(t_stack *stack, int number, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		if (stack->a.index[i] == number)
			close_program();
		i++;
	}
}

void length_verification(int length)
{
	if (length == 0)
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
