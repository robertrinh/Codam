/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 16:52:40 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/11/01 13:52:18 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief determines what fractal to render
 * @param t_data struct that contains which fractal to choose
*/
void	what_fractal(t_data *data)
{
	if (data->fract == MANDELBROT)
		mandelbrot(data);
	if (data->fract == JULIA)
		julia(data);
}

/**
 * @brief takes 4 integer parameters: r(ed),g(reen),b(lue) and a(lpha).
 * Combines these values using bitwise operators to create a colour.
 * @param t_data struct containing the colours
 * @param iter the amount of iterations done regarding colour changes
 * @return a 32-bit integer, representing a pixel colour.
*/
uint32_t	get_rgba(t_data *data, double iter)
{
	int	red;
	int	green;
	int	blue;
	int	alpha;

	red = (data->colour[r] * iter);
	green = (data->colour[g] * iter);
	blue = (data->colour[b] * iter);
	alpha = 255;
	return ((red << 24) | (green << 16) | (blue << 8) | alpha);
}

/**
 * @brief prints error message, exits the program
 * @param str The error message that will be printed
*/
void	terminator(char *str, t_data *data)
{
	ft_putendl_fd(str, STDERR_FILENO);
	if (data->mlx)
	{
		mlx_close_window(data->mlx);
		mlx_terminate(data->mlx);
	}
	exit(EXIT_FAILURE);
}
