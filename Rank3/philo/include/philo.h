/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/07 17:58:46 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/01/07 18:08:32 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_philo
{
	int	id;
	int	is_eating;
}	t_philo;

typedef struct s_data
{
	t_philo	philo;
}	t_data;

#endif