/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 16:26:25 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/09/15 17:46:52 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

// int main(void)
// {
//     printf("ik haat Makefiles");
//     return (0);
// }

int main(int ac, char **av)
{
    t_data  *data;

    data = ft_calloc(1, sizeof(data));
    if (!data)
        return (EXIT_FAILURE);
    init_bruv(data);
    
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
