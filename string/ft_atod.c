/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atod.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 15:21:43 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/10/26 15:52:18 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	get_decimal(char *str, double *decimal)
{
	double	actual_decimal;

	actual_decimal = 1;
	if (*str == '.')
		str++;
	while (*str)
	{
		*decimal = *decimal * 10 + (*str - '0');
		actual_decimal *= 10;
		str++;
	}
	*decimal /= actual_decimal;
}

double	ft_atod(char *str)
{
	int		sign;
	double	decimal;
	double	result;

	result = 0;
	decimal = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str != '.')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	get_decimal(str, &decimal);
	return (sign * (result + decimal));
}
// #include <stdio.h>
// int	main(void)
// {
// 	printf("does it work: %.2f\n", ft_atod("-1.23"));
// 	return (0);
// }