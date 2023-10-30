/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 16:21:03 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/10/30 17:15:35 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief code which contains the mathematical formula for a mandelbrot fractal.
 * @brief pseudocode found on wikipedia
 * @param orig_x x double containing x coordinate from mandelbrot function
 * @param orig_y y double containing x coordinate from mandelbrot function
 * @param max_iter max iterations that has been preset
 * @return amount of iterations done
*/
static double	get_mandelbrot(double orig_x, double orig_y, int max_iter)
{
	double	x;
	double	y;
	double	xtemp;
	double	iter;

	x = orig_x;
	y = orig_y;
	iter = 0;
	while ((x * x + y * y) <= 4 && iter < max_iter)
	{
		xtemp = (x * x) - (y * y) + orig_x;
		y = 2 * (x * y) + orig_y;
		x = xtemp;
		iter++;
	}
	return (iter);
}

/**
 * @brief checks position of coordinates with windowsize to put a pixel 
 * on regarded position.
 * mandelbrot formula is infinite amount of images while zooming.
 * Iterations determine the colour by multiplying them with each iteration.
 * @param t_data struct containing the data
*/
void	mandelbrot(t_data *data)
{
	double		x;
	double		y;
	double		iter;
	double		pos[2];
	uint32_t	colour;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		pos[X] = data->x[LEFT] + (x / WIDTH) * (data->x[RIGHT] - data->x[LEFT]);
		while (y < HEIGHT)
		{
			pos[Y] = data->y[UP] + (y / HEIGHT) * (data->y[DOWN] - data->y[UP]);
			iter = get_mandelbrot(pos[X], pos[Y], data->max);
			if (iter == data->max)
				colour = 0XFF;
			else
				colour = get_rgba(data, iter);
			mlx_put_pixel(data->img, x, y, colour);
			y++;
		}
		x++;
		y = 0;
	}
}
