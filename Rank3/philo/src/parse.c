/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 14:09:09 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/01/21 16:32:09 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	check_args(char **argv)
{
	int	str;
	int	i;

	str = 1;
	while (argv[str])
	{
		i = 0;
		while (argv[str][i])
		{
			if (!plato_isdigit(argv[str][i]))
				return (write(2, "Numeric/positive args only!\n", 29), false);
			i++;
		}
		str++;
	}
	return (true);
}

static bool	check_input(t_data *data, int argc)
{
	if (data->philo_count == 0 || data->philo_count > 200)
		return (write(2, "Max philo is 200!\n", 18), false);
	if (data->time_to_die == 0 || data->time_to_die > INT_MAX)
		return (write(2, "Invalid time to die!\n", 21), false);
	if (data->time_to_eat == 0 || data->time_to_eat > INT_MAX)
		return (write(2, "Invalid time to eat!\n", 21), false);
	if (data->time_to_sleep == 0 || data->time_to_sleep > INT_MAX)
		return (write(2, "Invalid time to sleep!\n", 23), false);
	if (argc == 6 && (data->must_eat == 0 || data->must_eat > INT_MAX))
		return (write(2, "Invalid amount of eating!\n", 27), false);
	return (true);
}

bool	assign_inputs(t_data *data, int argc, char **argv)
{
	data->philo_count = marcus_atoi(argv[1]);
	data->time_to_die = marcus_atoi(argv[2]);
	data->time_to_eat = marcus_atoi(argv[3]);
	data->time_to_sleep = marcus_atoi(argv[4]);
	if (argc == 5)
		data->must_eat = -1;
	if (argc == 6)
	{
		data->must_eat = marcus_atoi(argv[5]);
		data->has_eaten = true; // ! check later if needed
	}
	if (!check_input(data, argc))
		return (false);
	return (true);
}
