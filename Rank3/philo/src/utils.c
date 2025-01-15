/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 13:18:23 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/01/15 14:31:37 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	marcus_atoi(char *str)
{
	int	i;
	int	result;
	int	neg;

	i = 0;
	result = 0;
	neg = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (plato_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * neg);
}

void	*karl_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	memset(ptr, '\0', count * size);
	return (ptr);
}

bool	plato_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}
