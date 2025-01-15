/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/07 17:59:21 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/01/15 15:14:36 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static char	show_argc_error()
{
	write(2, "error! incorrect amount of args.\n", 34);
	write(2, "please input args in the following order:\n", 43);
	write(2, "./philo\n", 9);
	write(2, "number_of_philo\n", 17);
	write(2, "time_to_die\n", 13);
	write(2, "time_to_eat\n", 13);
	write(2, "time_to_sleep\n", 15);
	write(2, "[optional]: number_of_times_to_eat\n", 36);
	write(2, "example: ./philo 5 5 5 10 100\n", 31);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	
	data = NULL;
	if (argc != 5 && argc != 6)
		return (show_argc_error());
	if (!check_args(argv))
		return (1);
	data = parse_args(data, argc, argv);
	// run_simulation -> in here 1 philo en actual starting threads
	printf("ya done innit\n");
	return (EXIT_SUCCESS);
}
