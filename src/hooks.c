/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 16:03:05 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/10/30 18:05:17 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	iter_fract(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_EQUAL))
	{
		data->max += 7;
		what_fractal(data);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS))
	{
		data->max -= 7;
		what_fractal(data);
	}
}

static void	change_colour(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_X))
	{
		data->colour[R] -= 3;
		data->colour[G] -= 1;
		data->colour[B] -= 2;
		what_fractal(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_C))
	{
		data->colour[R] += 3;
		data->colour[G] += 1;
		data->colour[B] += 2;
		what_fractal(data);
	}
}

static void	reset_fract(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_R))
	{
		init_data(data);
		what_fractal(data);
	}
}

void	press_keys(mlx_key_data_t keydata, t_data *data)
{
	(void) keydata;
	iter_fract(data);
	change_colour(data);
	reset_fract(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		move_y(data, 0.05);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		move_y(data, -0.05);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		move_x(data, 0.05);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		move_x(data, -0.05);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE) || 
		mlx_is_key_down(data->mlx, MLX_KEY_Q))
		mlx_close_window(data->mlx);
}
