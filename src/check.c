/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 14:57:17 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/10/26 15:07:39 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	check_dots(char *av)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while (av[i])
	{
		if (av[i] == '.')
			count++;
		i++;
	}
	return (count);
}

bool string_check(char *av)
{
	int i;
	int count;
	int	dot;

	i = 1;
	count = 0;
	dot = check_dots(av);
	if (!ft_isdigit(av[0]) && !ft_isdigit(av[i]))
		return (false);
	while (av[i])
	{
		if (dot > 1)
			return (false);
		if (av[i] == '-' || av[i] == '+')
			count++;
		i++;
	}
	if (count >= 1)
		return (false);
	return (true);
}
