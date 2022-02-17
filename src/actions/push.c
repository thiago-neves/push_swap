#include "../../inc/push_swap.h"

static void subtract_old_number(t_array *giver)
{
	int i;

	i = 0;
	while (i < giver->length - 1)
	{
		giver->index[i] = giver->index[i + 1];
		i++;
	}
	giver->index[i] = 0;
}

static void receive_new_number(t_array *receiver, int new_number)
{
	int holder;
	int new_holder;
	int i;

	i = 0;
	new_holder = new_number;
	while (i <= receiver->length)
	{
		holder = new_holder;
		new_holder = receiver->index[i];
		receiver->index[i] = holder;
		i++;
	}
}

static void push(t_array *receiver, t_array *giver)
{
	receive_new_number(receiver, giver->index[0]);
	subtract_old_number(giver);
	receiver->length++;
	giver->length--;
}

void push_a(t_stack *stack)
{
	if (stack->b.length > 0)
		push(&stack->a, &stack->b);
	printf("pa\n");
}

void push_b(t_stack *stack)
{
	if (stack->a.length > 0)
		push(&stack->b, &stack->a);
	printf("pb\n");
}
