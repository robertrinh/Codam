/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_bruv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/08 17:37:22 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/10/27 16:35:01 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief initializes struct
 * @param t_data The data struct
*/
static void	init_data(t_data *data)
{
	data->x[0] = -2;
	data->x[1] = 2;
	data->y[0] = -2;
	data->y[1] = 2;
	data->max = 100;
	data->colour[R] = 2;
	data->colour[G] = 4;
	data->colour[B] = 6;
	//colours erbij doen?
}
/**
 * @brief counts how many dots are found in the string
 * @param av pointer to the string given in the av
 * @return amount of dots count
*/
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

/**
 * @brief Counts amount of -+ in the string.
 * starting from the 2nd character.
 * @param av pointer to the string given in the av
 * @return false is there are >1 icons found,
 * @return true when string is correct with only 1 icon found
*/
static bool	string_check(char *av)
{
	int	i;
	int	count;
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

/**
 * @brief parses arguments and presets the fractal
 * @param ac The argument count
 * @param av The argument vector
 * @param t_data the data struct
*/
static void	check_input(t_data *data, int ac, char **av)
{
	if (ac == 1)
		terminator("try -> ./fractol [julia/mandelbrot] [x] [y]", data);
	if (!ft_strncmp(av[1], "mandelbrot", 11) && ac == 2)
		data->fract = MANDELBROT;
	else if (!ft_strncmp(av[1], "julia", 6) && ac == 4)
	{
		data->fract = JULIA;
		if (!string_check(av[2]) || !string_check(av[3]))
			terminator("gimme some valid coordinates!", data);
		data->julia_x = ft_atod(av[2]);
		data->julia_y = ft_atod(av[3]);
		if (data->julia_x < -2 || data->julia_x > 2)
			terminator("values between -2 and 2, good sir", data);
		if (data->julia_y < -2 || data->julia_y > 2)
			terminator("values between -2 and 2, good sir", data);
	}
	else
		terminator("try ./fractol [julia/mandelbrot] [x] [y]", data);
	init_data(data);
	//color palette regelen?
}

/**
 * @brief Initialising of the program with mlx and parsing
 * @param t_data the data struct
 * @param ac the argument count
 * @param av the argument vector
*/
void	init_bruv(t_data *data, int ac, char **av)
{
	ft_bzero(data, sizeof(t_data));
	check_input(data, ac, av);
	data->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!(data->mlx))
		terminator("mlx failed, init", data);
	mlx_set_setting(MLX_STRETCH_IMAGE, true); //nodig?
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!(data->img))
		terminator("mlx new image failed", data);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == -1)
		terminator("image to window failed", data);
}
