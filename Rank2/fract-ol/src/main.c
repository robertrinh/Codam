/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 16:26:25 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/11/01 14:21:48 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	leaks_check(void)
{
	system("leaks fractol");
}

int	main(int ac, char **av)
{
	t_data	data;

	init_bruv(&data, ac, av);
	what_fractal(&data);
	mlx_key_hook(data.mlx, (mlx_keyfunc) press_keys, &data);
	mlx_scroll_hook(data.mlx, (mlx_scrollfunc) zoom_in_n_out, &data);
	mlx_loop(data.mlx);
	mlx_close_window(data.mlx);
	mlx_terminate(data.mlx);
	// atexit(&leaks_check);
	return (EXIT_SUCCESS);
}

//MLX tings to implement:
//ESC button
//mouse wheel zoom in and out
//bonus: moving view by pressing arrow keys
//bonus: zoom follows mouse position

//samenvoegen MLX42 /libft (submodule usen!) en compilen mbt makefile
//fix pixel op scherm --> open window (via MLX) voor begrijpen --> MLX_Put_pixel
//colour van pixel/ size pixel proberen
//pseudo code van mandel/julia via wikipedia

//proberen toe te passen
