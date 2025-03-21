/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/07 17:58:46 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/01/30 19:27:23 by robertrinh    ########   odam.nl         */
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

# define FORK_MSG "has taken a fork"
# define EAT_MSG "is eating"
# define SLEEP_MSG "is sleeping"
# define THINK_MSG "is thinking"
# define DEAD_MSG "died"

typedef enum p_status
{
	DEAD,
	ALIVE
}	t_status;

typedef enum p_meals
{
	UNFINISHED,
	FINISHED
}	t_meals;

typedef struct s_philo	t_philo;

/**
 * @param philo_count amount of philo's given as input
 * @param time_to_sleep time allowed for philo to sleep
 * @param time_to_eat time allowed for the philo to eat
 * @param time_to_think time allowed for the philo to think
 * @brief struct containing general information of the program.
 */
typedef struct s_data
{
	t_philo			*philo;
	size_t			philo_count;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			must_eat;
	unsigned long	start_time;
	bool			philo_check;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printing;
	pthread_mutex_t	eating;
	pthread_mutex_t	monitor;
}	t_data;

/**
 * @param id each unique ID of a thread (philo)
 * @param fork_left mutex assigned as left fork, unique to each philo
 * @param fork_right pointer mutex assigned as right fork, unique to each philo
 * @brief struct containing the data needed for each philo
 */
typedef struct s_philo
{
	pthread_t			t_id;
	size_t				id;
	size_t				meal_count;
	pthread_mutex_t		fork_left;
	pthread_mutex_t		*fork_right;
	unsigned long		last_eaten;
	t_data				*data;
}	t_philo;

// free.c
void			free_forks(t_data *data, size_t i);
void			free_freud(t_data *data);

// init_bruv.c
t_data			*innit(t_data *data, int argc, char **argv);

// monitor.c
void			monitor(t_data *data);

// parse.c
bool			assign_inputs(t_data *data, int argc, char **argv);
bool			check_args(char **argv);

// routine_helper.c
void			drop_forks(t_philo *philo, bool fork_left, bool fork_right);
unsigned long	time_diff(unsigned long input_time);
void			waiting_for(unsigned long time);
void			*single_philo(t_data *data);

// routine.c
bool			check_routine(t_philo *philo);
void			*routine(void *philosopher);

// utils.c
bool			print_message(t_philo *philo, char *msg);
unsigned long	retrieve_time(void);
size_t			marcus_atoi(char *str);
void			*karl_calloc(size_t count, size_t size);
bool			plato_isdigit(int c);

#endif