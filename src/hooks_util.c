/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks_util.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/30 15:29:02 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/10/30 17:06:16 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief zooms in and out of the fractal. then renders the image again
 * @param delta_x the changed (delta) x coordinate
 * @param delta_y the changed (delta) y coordinate
*/
void	zoom_in_n_out(double delta_x, double delta_y, t_data *data)
{
	double	zoom_factor;
	
	(void)delta_x;
	if (delta_y > 0)
		zoom_factor = 0.8;
	else
		zoom_factor = 1.2;
	data->x[LEFT] *= zoom_factor;
	data->x[RIGHT] *= zoom_factor;
	data->y[UP] *= zoom_factor;
	data->y[DOWN] *= zoom_factor;
	what_fractal(data);
}

void	move_x(t_data *data, double amount)
{
	data->x[LEFT] += amount;
	data->x[RIGHT] += amount;
	what_fractal(data);
}

void	move_y(t_data *data, double amount)
{
	data->y[UP] += amount;
	data->y[DOWN] += amount;
	what_fractal(data);
}
