/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine_helper.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/24 16:06:14 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/01/27 13:32:29 by robertrinh    ########   odam.nl         */
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

/**
 * @brief gets the time difference between current time and start time
 * @param philo the philo struct containing the starting time
 * @return the difference between current and start in milliseconds
 */
unsigned long	time_diff(t_philo *philo)
{
	unsigned long	current_time;

	current_time = retrieve_time();
	return (current_time - philo->data->start_time);
}

/**
 * @param time the time given, f.e. time_to_die
 * @brief waits for x amount of time from the input
 */
// wait for given amount of time from the input
void	waiting_for(unsigned long time)
{
	unsigned long	start;

	start = retrieve_time();
	while ((retrieve_time() - start) < time)
		usleep(100);
}

/**
 * @brief function hardcoded for single philosopher
 * @param data the data struct needed
 * @note takes a fork and can't eat because 2 is needed, then dies
 * @return NULL which indicates the success of the thread
 */
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
