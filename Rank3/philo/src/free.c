/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/17 16:22:50 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/01/21 14:10:50 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	destroy_mutex(t_data *data)
{
	size_t	i;

	i = 0;
	pthread_mutex_destroy(&data->printing);
	pthread_mutex_destroy(&data->eating);
	pthread_mutex_destroy(&data->monitor);
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}

void	free_forks(t_data *data, size_t i)
{
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i--;
	}
	free(data->forks);
}

void	free_freud(t_data *data)
{
	destroy_mutex(data);
	if (data->philo)
		free(data->philo);
	if (data->forks)
		free(data->forks);
	if (data)
		free(data);
}
