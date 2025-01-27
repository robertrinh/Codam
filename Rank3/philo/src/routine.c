/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 12:48:56 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/01/27 12:20:10 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	chappings(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	if (!print_message(philo, FORK_MSG))
		return (drop_forks(philo, true, false), false);
	pthread_mutex_lock(philo->fork_right);
	if (!print_message(philo, FORK_MSG))
		return (drop_forks(philo, true, true), false);
	if (!print_message(philo, EAT_MSG))
		return (drop_forks(philo, true, true), false);
	pthread_mutex_lock(&philo->data->eating);
	philo->last_eaten = retrieve_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->data->eating);
	waiting_for(philo->data->time_to_eat);
	drop_forks(philo, true, true);
	return (true);
}

static bool	sleeping(t_philo *philo)
{
	if (!print_message(philo, SLEEP_MSG))
		return (false);
	waiting_for(philo->data->time_to_sleep);
	return (true);
}
static bool	thinking(t_philo *philo)
{
	if (!print_message(philo, THINK_MSG))
		return (false);
	return (true);
}

// monitors if philo has died or not from specific thread
bool	check_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->monitor);
	if (philo->data->philo_check == false)
		return (pthread_mutex_unlock(&philo->data->monitor), false);
	pthread_mutex_unlock(&philo->data->monitor);
	return (ALIVE);
}

void	*routine(void *philosopher)
{
	t_philo	*philo;
	bool	completed;

	philo = (t_philo *)philosopher;
	if (philo->id % 2)
		usleep(1000);
	while (check_routine(philo))
	{
		completed = chappings(philo);
		if (!completed)
			return (NULL);
		completed = sleeping(philo);
		if (!completed)
			return (NULL);
		completed = thinking(philo);
		if (!completed)
			return (NULL);
	}
	return (NULL);
}
