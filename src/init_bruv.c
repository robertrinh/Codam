/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_bruv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/08 17:37:22 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/10/26 16:35:30 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	init_data(t_data *data)
{
	data->x[0] = -2;
	data->x[1] = 2;
	data->y[0] = -2;
	data->y[1] = 2;
	data->max = 100;
	//colours erbij doen?
}

static void	check_input(t_data *data, int ac, char **av)
{
	if (ac == 1)
		terminator("more inputs! -> ./fractol [julia/man] [x] [y]", data);
	if (!ft_strncmp(av[1], "mandelbrot", 11) && ac == 2)
        data->fract = 1;
    else if (!ft_strncmp(av[1], "julia", 6) && ac == 4)
	{
		data->fract = 2;
		if (!string_check(av[2]) || !string_check(av[3]))
			terminator("gimme some valid coordinates!", data);
		//build an atod
		//check if it falls between -2 and 2
	}
	else
		terminator("what yu doin?? use ./fractol [julia/man] [x] [y]", data);
	init_data(data);
	//color palette regelen?
		
}

void    init_bruv(t_data *data, int ac, char **av)
{
	ft_memset(data, 0 , sizeof(t_data));
	check_input(data, ac, av);
	//init mlx
}



