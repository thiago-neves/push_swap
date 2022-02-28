#include "../inc/push_swap.h"

int main(int array_length, char **numbers)
{
	t_stack stack;

	stack.length = array_length - 1;
	set_stacks(&stack, numbers);
	if (stack.length <= 5)
		small_stack(&stack);
	else
		big_stack(&stack);
	//int i = 0;
	//printf("\na\tb\n");
	//while (i < stack.length)
	//{
	//	printf("%d\t%d\n", stack.a.index[i], stack.b.index[i]);
	//	i++;
	//}
	return (0);
}
