/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_bruv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/08 17:37:22 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/10/26 18:07:48 by qtrinh        ########   odam.nl         */
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

static bool string_check(char *av)
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
		data->julia_x = ft_atod(av[2]);
		data->julia_y = ft_atod(av[3]);
		if (data->julia_x < -2 || data->julia_x > 2)
			terminator("between -2 and 2, good sir", data);
		if (data->julia_y < -2 || data->julia_y > 2)
			terminator("between -2 and 2, good sir", data);
	}
	else
		terminator("what yu doin?? use ./fractol [julia/man] [x] [y]", data);
	init_data(data);
	//color palette regelen?
}

void    init_bruv(t_data *data, int ac, char **av)
{
	mlx_t*	mlx;
	
	ft_bzero(data, sizeof(t_data));
	check_input(data, ac, av);
	// mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "fractol", true)))
		terminator("mlx failed, init", data);
	mlx_set_setting(MLX_STRETCH_IMAGE, true); //nodig?
	// data->mlx = mlx;
	// data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!(data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT)))
		terminator("mlx new image failed", data);
}
