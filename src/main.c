/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 16:26:25 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/10/26 13:17:17 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

// int main(void)
// {
//     printf("ik haat Makefiles\n");
//     return (0);
// }

int main(int ac, char **av)
{
    t_data	data;

    init_bruv(&data, ac, av);
    //mlx key hook -> scroll hook -> close -> image to window
    //mlx_terminate(data.mlx)
    // mlx_loop(data.mlx);
    // mlx_terminate(data.mlx);
    return (EXIT_SUCCESS);
}

//samenvoegen MLX42 /libft (submodule usen!) en compilen mbt makefile
//fix pixel op scherm --> open window (via MLX) voor begrijpen --> met MLX_Put_pixel
//colour van pixel/ size pixel proberen
//pseudo code van mandel/julia via wikipedia

//proberen toe te passen
