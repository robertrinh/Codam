/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 17:49:30 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/10/27 16:28:18 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief code which contains the mathematical formula for a julia fractal.
 * @brief pseudocode found on wikipedia
 * @param x x double containing x coordinate
 * @param y y double containing x coordinate
 * @param t_data struct that contains the julia coordinates input(atod'd)
 * @return amount of iterations done
*/
static double	get_julia(t_data *data, double x, double y)
{
	double xtemp;
	int	iter;
	
	iter = 0;
		while ((x * x + y * y) <= 4 && iter < data->max)
	{
		xtemp = (x * x) - (y * y) + data->julia_x;
		y = 2 * (x * y) + data->julia_y;
		x = xtemp;
		iter++;
	}
	return (iter);
}

/**
 * @brief checks position of coordinates with windowsize to put a pixel 
 * on regarded position.
 * julia formula is infinite amount of images while zooming.
 * Iterations determine the colour by multiplying them with each iteration.
 * @param t_data struct containing the data
*/
void	julia(t_data *data)
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
			iter = get_julia(data, pos[X], pos[Y]);
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
