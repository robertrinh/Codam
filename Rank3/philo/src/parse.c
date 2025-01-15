/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 14:09:09 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/01/15 14:52:19 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	assign_inputs(t_data *p, int argc, char **argv)
{
	p->philo_count = marcus_atoi(argv[1]);
	p->time_to_die = marcus_atoi(argv[2]);
	p->time_to_eat = marcus_atoi(argv[3]);
	p->time_to_sleep = marcus_atoi(argv[4]);
	if (argc == 5)
		p->must_eat = -1;
	if (argc == 6)
	{
		p->must_eat = marcus_atoi(argv[5]);
		p->has_eaten = true; // ! check later if needed
	}
}

t_data	*parse_args(t_data *data, int argc, char **argv)
{
	// t_data	*p;

	data = karl_calloc(sizeof(t_data), 1);
	if (!data)
		return (write(2, "malloc\n", 8), NULL);
	assign_inputs(data, argc, argv);
	// if (!input_check(data, argc, argv))
	// {
	// 	write(2, "input exceeds max_int, choose a integer between\n", 48);
	// 	return (free(data), NULL);
	// }
	return (data);
}
