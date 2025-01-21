/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 12:48:56 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/01/21 15:13:50 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	single_philo(t_data *data)
{
	size_t	i;

	i = 0;
	pthread_mutex_lock(data->philo[0].fork_left);
	printf("%zu %zu has taken a fork\n", i, data->philo[0].id + 1);
	pthread_mutex_unlock(data->philo[0].fork_left);
	// wait for time to die;
	printf("%zu %zu has died\n", i, data->philo[0].id + 1);
}

void	routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
}
