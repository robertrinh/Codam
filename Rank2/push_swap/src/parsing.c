/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 15:18:25 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/21 18:01:24 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static bool	duplicate_check(char **temp_array)
{
	int	i;
	int	j;

	i = 0;
	while (temp_array[i])
	{
		j = i + 1;
		while (temp_array[j])
		{
			if (ft_ayetoi(temp_array[i]) == ft_ayetoi(temp_array[j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static bool	number_check(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-')
		i++;
	if (argv[i] == '\0')
		terminator();
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

void	input_check(int argc, char **argv)
{
	char	**temp_array;
	long	temp_argv;
	int		i;

	i = 0;
	if (argc == 2)
	{
		temp_array = ft_split(argv[1], ' ');
		if (!temp_array)
			exit(EXIT_FAILURE);
	}
	else
		temp_array = argv + 1;
	while (temp_array[i])
	{
		temp_argv = ft_ayetoi(temp_array[i]);
		if (temp_argv > INT_MAX || temp_argv < INT_MIN)
			terminator();
		if (duplicate_check(temp_array) || !number_check(temp_array[i]))
			terminator();
		i++;
	}
	if (argc == 2)
		ft_free_2d(temp_array);
}
