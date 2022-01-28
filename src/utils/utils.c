#include "../inc/push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static void	sign_switch(const char *str, size_t i, int *sign)
{
	if (str[i] == '+' && *sign == 1)
		*sign = 1;
	else if (str[i] == '-' && *sign == -1)
		*sign = 1;
	else if (str[i] == '+' && *sign == -1)
		*sign = -1;
	else if (str[i] == '-' && *sign == 1)
		*sign = -1;
}

long				ft_atoi(const char *str)
{
	long	number;
	int		sign;
	size_t	i;

	number = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		sign_switch(str, i, &sign);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + (str[i++] - '0');
	if (number < 0)
		return ((sign > 0) ? -1 : 0);
	return (sign * number);
}