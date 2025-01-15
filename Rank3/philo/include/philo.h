/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/07 17:58:46 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/01/15 14:49:07 by qtrinh        ########   odam.nl         */
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
# include <stdbool.h>
# include <limits.h>

/**
 * @param id each unique ID of a thread (philo)
 * @param fork_left mutex assigned as left fork, unique to each philo
 * @param fork_right pointer mutex assigned as right fork, unique to each philo
 * @param meal_lock the mutex lock to prevent race conditions for the meal
 * @brief struct containing the data needed for each philo
 */
typedef struct s_philo
{
	int				id;
	int				meal_count;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	meal_lock;
}	t_philo;

typedef struct s_monitor
{
	/* data */
}	t_monitor;


/**
 * @param philo_count amount of philo's given as input
 * @param time_to_sleep time allowed for philo to sleep
 * @param time_to_eat time allowed for the philo to eat
 * @param time_to_think time allowed for the philo to think
 * @param has_eaten check if philo has eaten or not
 * @brief struct containing general information of the program.
 */
typedef struct s_data
{
	t_philo	*philo;
	int		philo_count;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat;
	bool	has_eaten;
	//unsigned long	start_time;
}	t_data;

// checks.c
bool	check_args(char **argv);

// parse.c
t_data	*parse_args(t_data *data, int argc, char **argv);

// utils.c
int		marcus_atoi(char *str);
void	*karl_calloc(size_t count, size_t size);
bool	plato_isdigit(int c);

#endif