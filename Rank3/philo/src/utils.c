/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 13:18:23 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/01/24 19:22:57 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->printing);
	printf("%ld %zu %s\n", time_diff(philo), philo->id, msg);
	pthread_mutex_unlock(&philo->data->printing);
}

/**
 * @param void
 * @brief get the current time from 1979 onwards
 * @note converting seconds to milliseconds by multiplying tv.tv_sec * 1000
 * @note converting microseconds to milliseconds by diving tv.tv_sec / 1000
 * @return time in milliseconds after converting
 */
unsigned long	retrieve_time(void)
{
	struct timeval	tv;
	unsigned long	time_in_ms;

	if (gettimeofday(&tv, NULL) == -1)
		return (write(2, "Error gettimeofday\n", 20), 42);
	time_in_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time_in_ms);
}

size_t	marcus_atoi(char *str)
{
	size_t	i;
	size_t	result;
	size_t	neg;

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
