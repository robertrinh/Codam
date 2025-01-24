/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 12:48:56 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/01/24 22:19:48 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	chappings(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	print_message(philo, FORK_MSG);
	pthread_mutex_lock(philo->fork_right);
	print_message(philo, FORK_MSG);
	print_message(philo, EAT_MSG);
	pthread_mutex_lock(&philo->data->eating);
	philo->last_eaten = retrieve_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->data->eating);
	waiting_for(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

static void	sleeping(t_philo *philo)
{
	print_message(philo, SLEEP_MSG);
	waiting_for(philo->data->time_to_sleep);
}
static void	thinking(t_philo *philo)
{
	print_message(philo, THINK_MSG);
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

	philo = (t_philo *)philosopher;
	if (philo->id % 2)
		usleep(1000);
	while (check_routine(philo))
	{
		chappings(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
