/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 14:58:51 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/01/24 17:53:16 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	philo_has_finished(t_data *data)
{
	//! max count = true, else false
	if (data->philo->meal_count == data->must_eat)
		return (true);
	return (false);
}

static bool	philo_death_check(t_data *data)
{
	//! death = true, alive is false
	unsigned long	time;

	pthread_mutex_lock(&data->eating);
	time = retrieve_time() - data->philo->last_eaten;
	if (time > data->time_to_die)
	{
		pthread_mutex_unlock(&data->eating);
		pthread_mutex_lock(&data->monitor);
		data->philo_check = DEAD;
		pthread_mutex_unlock(&data->monitor);
		print_message(data->philo, DEAD_MSG);
		return (DEAD);
	}
	pthread_mutex_unlock(&data->eating);
	//* lock mutex
	return (ALIVE);
}

void	monitor(t_data *data)
{
	if (data->must_eat == SSIZE_MAX)
	{
		while (1)
			if (philo_death_check(data) == DEAD)
			{
				printf("returning dead philo\n");
				return ;
			}
		//* death check philo, infinite loop
	}
	while (1)
		if (philo_death_check(data) == DEAD || philo_has_finished(data))
			return ;
	//* death check philo + eat_count_check
}
