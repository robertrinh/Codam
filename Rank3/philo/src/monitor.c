/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 14:58:51 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/01/24 22:12:27 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	philo_has_finished(t_data *data)
{
	size_t	i;
	size_t	meal_finish;

	i = 0;
	meal_finish = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&data->eating);
		if (data->philo[i].meal_count >= data->must_eat)
			meal_finish++;
		pthread_mutex_unlock(&data->eating);
		i++;
	}
	if (meal_finish == data->philo_count)
	{
		pthread_mutex_lock(&data->monitor);
		data->philo_check = false;
		pthread_mutex_unlock(&data->monitor);
		return (true);
	}
	return (false);
}

static bool	philo_death_check(t_data *data)
{
	unsigned long	time;

	pthread_mutex_lock(&data->eating);
	time = retrieve_time() - data->philo->last_eaten;
	if (time > data->time_to_die)
	{
		pthread_mutex_lock(&data->monitor);
		data->philo_check = false;
		pthread_mutex_unlock(&data->eating);
		pthread_mutex_unlock(&data->monitor);
		print_message(data->philo, DEAD_MSG);
		return (DEAD);
	}
	pthread_mutex_unlock(&data->eating);
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
	}
	while (1)
	{
		if (philo_death_check(data) == DEAD)
			return ;
		if (philo_has_finished(data))
		{
			printf("returning\n");
			return ;
		}
	}
}
