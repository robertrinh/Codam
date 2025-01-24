/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine_helper.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 16:06:14 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/01/24 17:08:45 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// wait for given amount of time from the input
void	waiting_for(unsigned long time)
{
	unsigned long	start;

	start = retrieve_time();
	while((retrieve_time() - start) < time)
		usleep(200);
}

void	*single_philo(t_data *data)
{
	size_t	i;

	i = 0;
	pthread_mutex_lock(data->philo[0].fork_left);
	// print_message(data->philo, FORK_MSG);
	printf("%zu %zu has taken a fork\n", i, data->philo[0].id + 1);
	pthread_mutex_unlock(data->philo[0].fork_left);
	waiting_for(data->time_to_die);
	// print_message(data->philo, DEAD_MSG);
	printf("%zu %zu has died\n", i, data->philo[0].id + 1);
	return (NULL);
}
