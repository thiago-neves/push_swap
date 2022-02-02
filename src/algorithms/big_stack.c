#include "../../inc/push_swap.h"

void sort_chunk(t_stack *stacks, int last_chunk, int chunk)
{
	(void)stacks;
	(void)last_chunk;


	printf("%d\n", chunk);
}

void sort_big_stack(t_stack *stacks, int chunk_number)
{
	int i;
	int chunk;

	i = 0;
	chunk = stacks->a.length / chunk_number;
	while (stacks->a.length > chunk * i)
	{
		sort_chunk(stacks, chunk * (i - 1), chunk * i);
		i++;
	}
}

void big_stack(t_stack *stacks)
{
	sort_big_stack(stacks, 5);
	printf("Big stack: %d\n", stacks->length);
}
