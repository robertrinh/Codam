/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/14 14:59:49 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/01/15 15:14:28 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	check_args(char **argv)
{
	int	str;
	int	i;

	str = 1;
	i = 0;
	while (argv[str])
	{
		if (marcus_atoi(argv[str]) < 0 || marcus_atoi(argv[str]) > INT_MAX)
		{
			write(2, "error, no positive integer or overflowed INT_MAX\n", 50);
			return (false);
		} // ! check how to combat overflow
		i = 0;
		while (argv[str][i])
		{
			if (!plato_isdigit(argv[str][i]))
			{
				write(2, "numeric arguments only!\n", 24);
				return (false);
			}
			i++;
		}
		str++;
	}
	return (true);
}
