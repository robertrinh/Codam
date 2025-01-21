/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 14:58:51 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/01/21 17:29:49 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	philo_has_finished(t_data *data)
{
	//! max count = true, else false
	return (false);
}

static bool	philo_death_check(t_data *data)
{
	//! death = true, alive is false
	//* lock mutex
	return (false);
}

void	monitor(t_data *data)
{
	if (data->must_eat == -1)
	{
		while (1)
			if (philo_death_check(data))
				return ;
		//* death check philo, infinite loop
	}
	while (1)
		if (philo_death_check(data) || philo_has_finished(data))
			return ;
	//* death check philo + eat_count_check
}
