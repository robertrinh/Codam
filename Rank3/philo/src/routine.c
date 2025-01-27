/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 12:48:56 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/01/27 15:17:18 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief prints the eating message when given 2 forks and did not die
 * and then eats for time_to_eat amount
 * @param philo the philo struct needed
 * @note mutex for the forks left + right to avoid deadlock + data race
 * @note 
 * @return true is succeeded, false if philo died
 */
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

/**
 * @brief monitors if philo has died or not
 * @param philo the philo struct
 * @return false if a philo died, ALIVE(true) if philo is alive
 */
// monitors if philo has died or not from specific thread
bool	check_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->monitor);
	if (philo->data->philo_check == false)
		return (pthread_mutex_unlock(&philo->data->monitor), false);
	pthread_mutex_unlock(&philo->data->monitor);
	return (ALIVE);
}

/**
 * @brief the routine from the philo's until one dies
 * @param void pointer which will be recasted to the philo struct
 * @return NULL when a philo died, indicating the thread finished
 */
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
