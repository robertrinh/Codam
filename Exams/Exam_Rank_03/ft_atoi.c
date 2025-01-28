// Assignment name  : ft_atoi
// Expected files   : ft_atoi.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str to an integer (type int)
// and returns it.

// It works much like the standard atoi(const char *str) function, see the man.

// Your function must be declared as follows:

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int i = 0, result = 0, neg = 1;
	while (str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * neg);
}

#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char *num;
	int	actual_num;
	int	actual_atoi;

	num = "      	-1123 +500";
	actual_num = ft_atoi(num);
	actual_atoi = atoi(num);
	printf("atointeger: %d\n", actual_num);
	printf("actual atoi: %d\n", actual_atoi);
	return (0);
}
