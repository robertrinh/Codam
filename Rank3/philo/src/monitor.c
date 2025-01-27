/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 14:58:51 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/01/27 13:19:45 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	print_dead(t_data *data)
{
	pthread_mutex_lock(&data->printing);
	printf("%ld %zu %s\n", time_diff(data->philo), data->philo->id, DEAD_MSG);
	pthread_mutex_unlock((&data->printing));
}

static bool	philo_has_finished(t_data *data)
{
	size_t	i;
	size_t	meal_finish;

	i = 0;
	meal_finish = 0;
	if (data->must_eat != SSIZE_MAX)
	{
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
			return (FINISHED);
		}
	}
	return (UNFINISHED);
}

static bool	philo_death_check(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&data->eating);
		if (time_diff(data->philo) > data->time_to_die)
		{
			pthread_mutex_unlock(&data->eating);
			pthread_mutex_lock(&data->monitor);
			data->philo_check = false;
			pthread_mutex_unlock(&data->monitor);
			print_dead(data);
			return (DEAD);
		}
		pthread_mutex_unlock(&data->eating);
		i++;	
	}
	return (ALIVE);
}

void	monitor(t_data *data)
{
	while (1)
		if (philo_death_check(data) == DEAD || philo_has_finished(data))
			return ;
}
