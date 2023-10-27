/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 16:03:05 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/10/27 16:39:19 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	key_hook(void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
}
