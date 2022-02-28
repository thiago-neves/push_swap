#include "../../inc/push_swap.h"

void order_stack_a(t_stack *stacks, int index)
{
	if (index < stacks->a.length / 2)
		while (index > 0)
		{
			rotate_a(stacks);
			index--;
		}
	else
		while (index < stacks->a.length)
		{
			reverse_rotate_a(stacks);
			index++;
		}
}

int find_index_first_half(t_array *a, int last_chunk, int chunk)
{
	int i;
	int index;

	i = 0;
	index = -1;
	while (i < a->length / 2)
	{
		if (a->index[i] >= last_chunk && a->index[i] < chunk)
		{
			index = i;
			i = a->length;
		}
		i++;
	}
	return (index);
}

int find_index_second_half(t_array *a, int last_chunk, int chunk)
{
	int	i;
	int	index;

	i = a->length - 1;
	index = -1;
	while (i > a->length / 2)
	{
		if (a->index[i] >= last_chunk && a->index[i] < chunk)
		{
			index = i;
			i = 0;
		}
		i--;
	}
	return (index);
}

 int find_next_index(t_stack *stacks, int last_chunk, int chunk)
{
	int	hold_first;
	int	hold_second;

	hold_first = find_index_first_half(&stacks->a, last_chunk, chunk);
	hold_second = find_index_second_half(&stacks->a, last_chunk, chunk);
	if (hold_second == -1)
		return (hold_first);
	else if (hold_first == -1)
		return (hold_second);
	else if (hold_first <= stacks->a.length - hold_second)
		return (hold_first);
	else
		return (hold_second);
}

int find_position(t_array *a, t_array *b)
{
	int	i;
	int	smallest;
	int	biggest;

	i = 0;
	biggest = -1;
	smallest = -1;
	while (i < b->length - 1)
	{
		if (a->index[0] < b->index[i] && a->index[0] > b->index[i + 1])
		{
			//printf("\ninside_loop | Number: %d, smallest: %d\n", a->index[0], (i + 1));
			return (i + 1);
		}
		if (smallest == -1 || b->index[i] < b->index[smallest])
			smallest = i;
		if (b->index[i] > b->index[biggest])
			biggest = i;
		i++;
	}
	if (smallest == -1 || b->index[i] < b->index[smallest])
		smallest = i;
	if (b->index[i] > b->index[biggest])
		biggest = i;
	if (b->index[smallest] > a->index[0])
	{
		//printf("smalles/t\n");
		return (smallest + 1);
	}
	if (a->index[0] > b->index[biggest])
	{
		//printf("biggest %d\n", b->index[biggest]);
		return (biggest);
	}
	//printf("here\n");
	return (-1);
}

void push_to_stack_b(t_stack *stacks)
{
	int pos;

	if (stacks->b.length == 1)
	{
		push_b(stacks);
		if (stacks->b.index[1] > stacks->b.index[0])
			swap_b(stacks);
	}
	else if (stacks->b.length == 0)
		push_b(stacks);
	else
	{
		pos = find_position(&stacks->a, &stacks->b);
		if (pos > stacks->b.length / 2)
			while (stacks->b.length - pos != 0)
			{
				reverse_rotate_b(stacks);
				pos++;
			}
		else
			while (pos > 0)
			{
				rotate_b(stacks);
				pos--;
			}
		push_b(stacks);
	}
}

void sort_chunk(t_stack *stacks, int last_chunk, int chunk)
{
	int chunk_size;
	int number_index;

	chunk_size = chunk - last_chunk;
	while (chunk_size)
	{
		number_index = find_next_index(stacks, last_chunk, chunk);
	 	order_stack_a(stacks, number_index);
		push_to_stack_b(stacks);
		chunk_size--;
	}
}

void order_stack_b(t_stack *stacks)
{
	int i;
	int biggest;

	i = 0;
	biggest = -1;
	while (i < stacks->b.length)
	{
		if (stacks->b.index[i] > stacks->b.index[biggest] || biggest == -1)
			biggest = i;
		i++;
	}
	//printf("Biggest: %d, length: %d\n", stacks->b.index[biggest], stacks->b.length);
	if (biggest > stacks->b.length / 2)
		while (stacks->b.length - biggest != 0)
		{
			reverse_rotate_b(stacks);
			biggest++;
		}
	else
		while (biggest)
		{
			rotate_b(stacks);
			biggest--;
		}
	while (stacks->b.length)
		push_a(stacks);
}

void sort_big_stack(t_stack *stacks, int chunk_number)
{
 	int i;
 	int chunk;
	int	length;

 	i = 1;
	length = stacks->a.length;
 	chunk = length / chunk_number;
 	while (length >= chunk * i)
 	{
 		sort_chunk(stacks, chunk * (i - 1), chunk * i);
 		i++;
 	}
	sort_chunk(stacks, chunk * (i - 1), length);
	order_stack_b(stacks);
}

void big_stack(t_stack *stacks)
{
	(void)stacks;
	if (stacks->length < 100)
		sort_big_stack(stacks, 5);
	else
		sort_big_stack(stacks, 11);
}
