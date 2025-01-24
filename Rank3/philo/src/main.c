/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/07 17:59:21 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/01/24 18:07:53 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static char	show_argc_error(void)
{
	write(2, "error! incorrect amount of args.\n", 34);
	write(2, "please input args in the following order:\n", 43);
	write(2, "./philo\n", 9);
	write(2, "number_of_philo\n", 17);
	write(2, "time_to_die\n", 13);
	write(2, "time_to_eat\n", 13);
	write(2, "time_to_sleep\n", 15);
	write(2, "[optional]: number_of_times_to_eat\n", 36);
	write(2, "example: ./philo 5 800 200 200\n", 31);
	return (EXIT_FAILURE);
}

static void	join_threads(t_data *data, size_t thread_count)
{
	size_t	i;

	i = 0;
	while (i < thread_count)
	{
		if (pthread_join(data->philo[i].t_id, NULL) != 0)
		{
			write(2, "Error joining threads\n", 23);
			return ;
		}
		i++;
	}
}

static void	start_simulation(t_data *data)
{
	if (data->philo_count == 1)
		return (single_philo(data), join_threads(data, 0), free_freud(data));
	data->start_time = retrieve_time();
	monitor(data);
	//* end
	join_threads(data, data->philo_count);
	free_freud(data);
}

static bool	create_threads(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philo[i].t_id, NULL, &routine, \
			&data->philo[i]) != 0)
		{
			join_threads(data, i);
			free_freud(data);
			write(2, "Error creating threads\n", 24);
			return (false);
		}
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc != 5 && argc != 6)
		return (show_argc_error());
	if (!check_args(argv))
		return (EXIT_FAILURE);
	data = innit(data, argc, argv);
	if (!data)
		return (EXIT_FAILURE);
	if (!create_threads(data))
		return (EXIT_FAILURE);
	start_simulation(data);
	return (EXIT_SUCCESS);
}

//! issue: threads created instantly takes fork at 5 philo
//! 1 philo has 2 prints of taking a fork
//! after dead philo still runs -> no correct data lock?
//! seconds are not portrayed correctly -> should portray get time DIFFERENCE

// ! tests:
//* Do not test with more than 200 philosophers.

//* Do not test with time_to_die or time_to_eat or time_to_sleep set to values lower than 60 ms.

//* Test 1 800 200 200. The philosopher should not eat and should die.

//* Test 5 800 200 200. No philosopher should die.

//* Test 5 800 200 200 7. No philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times.

//* Test 4 410 200 200. No philosopher should die.

//* Test 4 310 200 100. One philosopher should die.

//* Test with 2 philosophers and check the different times: a death delayed by more than 10 ms is unacceptable.
