#include "../../inc/push_swap.h"

void push_to_stack_b(t_stack *stacks, int index)
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
	push_b(stacks);
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

 void sort_chunk(t_stack *stacks, int last_chunk, int chunk)
 {
 	int chunk_size;
 	int number_index;

 	chunk_size = chunk - last_chunk;
 	while (chunk_size)
 	{
 		number_index = find_next_index(stacks, last_chunk, chunk);
	 	push_to_stack_b(stacks, number_index);
 		chunk_size--;
 	}
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
 }

void big_stack(t_stack *stacks)
{
	(void)stacks;
	sort_big_stack(stacks, 5);
}
