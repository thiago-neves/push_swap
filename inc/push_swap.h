#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_INT_NUM 2147483647
#define MIN_INT_NUM -2147483648


typedef struct s_array
{
	int		*index;
	int		length;
}				t_array;

typedef struct s_stack
{
	t_array	a;
	t_array	b;
	int		has_zero;
	int		array_length;
}				t_stack;

void	close_without_message();
void	close_program_with_tip();
void	small_stack(t_stack *stack);
void	close_program();
int		ft_isdigit(int c);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_s(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
long	ft_atoi(const char *str);
void	integer_verification(char **arguments);
void	length_verification(int arguments_length);
void	set_stacks(t_stack *stack, char **numbers);
void	verify_duplication(t_stack *stack, int number);
