#include "../../inc/push_swap.h"

void close_program()
{
	write(1, "Error\n", 6);
	exit(1);
}

void close_program_with_tip()
{
	write(1, "The program needs arguments to execute properly\n", 48);
	exit(1);
}

void close_without_message()
{
	exit(1);
}