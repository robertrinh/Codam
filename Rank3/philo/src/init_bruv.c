/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_bruv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 18:03:30 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/01/21 17:31:28 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	philos_innit(t_data *data)
{
	size_t	i;

	i = 0;
	data->philo = karl_calloc(sizeof(t_philo), data->philo_count);
	if (!data->philo)
		return (write(2, "philo malloc fail\n", 19), free_freud(data), false);
	while (i < data->philo_count)
	{
		data->philo[i].id = i + 1;
		data->philo[i].fork_right = &data->forks[i];
		data->philo[i].fork_left = &data->forks[(i + 1) % data->philo_count];
		data->philo[i].meal_count = 0;
		//data->philo[i].meal_lock = pthread_mutex_init; 
		data->philo[i].data = data;
		i++;
	}
	return (true);
}

static bool	forks_innit(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	data->forks = karl_calloc(sizeof(pthread_mutex_t), data->philo_count);
	if (!data->forks)
		return (write(2, "fork init fail\n", 16), false);
	while (i < data->philo_count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			j = 0;
			while (j < i)
			{
				pthread_mutex_destroy(&data->forks[j]);
				j++;
			}
			free_forks(data, i);
			return (write(2, "forks mutex init fail\n", 23), false);
		}
		i++;
	}
	return (true);
}

static bool	mutex_innit(t_data *data)
{
	size_t			i;
	size_t			j;
	pthread_mutex_t	*mutex[3];

	i = 0;
	mutex[0] = &data->printing;
	mutex[1] = &data->eating;
	mutex[2] = &data->monitor;
	while (i < 3)
	{
		if (pthread_mutex_init(mutex[i], NULL) != 0)
		{
			j = 0;
			while (j < i)
			{
				pthread_mutex_destroy(mutex[j]);
				j++;
			}
			return (write(2, "mutex init fail\n", 17), false);
		}
		i++;
	}
	return (true);
}

t_data	*innit(t_data *data, int argc, char **argv)
{
	data = karl_calloc(sizeof(t_data), 1);
	if (!data)
		return (write(2, "malloc\n", 8), NULL);
	if (!assign_inputs(data, argc, argv))
		return (free(data), NULL);
	if (!mutex_innit(data) || !forks_innit(data) || !philos_innit(data))
		return (free_freud(data), NULL);
	return (data);
}
