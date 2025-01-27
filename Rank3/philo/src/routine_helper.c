/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine_helper.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 16:06:14 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/01/27 12:19:20 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	drop_forks(t_philo *philo, bool fork_left, bool fork_right)
{
	if (fork_left)
		pthread_mutex_unlock(philo->fork_left);
	if (fork_right)
		pthread_mutex_unlock(philo->fork_right);
}

unsigned long	time_diff(t_philo *philo)
{
	unsigned long	current_time;

	current_time = retrieve_time();
	return (current_time - philo->data->start_time);
}

// wait for given amount of time from the input
void	waiting_for(unsigned long time)
{
	unsigned long	start;

	start = retrieve_time();
	while((retrieve_time() - start) < time)
		usleep(100);
}

void	*single_philo(t_data *data)
{
	size_t	i;

	i = 0;
	pthread_mutex_lock(data->philo[0].fork_left);
	printf("%zu %zu has taken a fork\n", i, data->philo[0].id);
	pthread_mutex_unlock(data->philo[0].fork_left);
	waiting_for(data->time_to_die);
	printf("%zu %zu has died\n", i, data->philo[0].id);
	return (NULL);
}
