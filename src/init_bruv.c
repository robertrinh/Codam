/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_bruv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/08 17:37:22 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/09/15 17:57:07 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void    init_bruv(t_data *data)
{
    ft_bzero(data, sizeof(data));
    data->mlx = mlx_init(WIDTH, HEIGHT, "fractal window", true);
    if (!data->mlx)
        terminator("no mlx", 2);
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    if (!data->img)
    {
        mlx_close_window(data->mlx);
        terminator("window buffer allocation fail", 2);
    }
    if (mlx_image_to_window(data->mlx, data->img, 0, 0) == -1)
    {
        mlx_close_window(data->mlx);
        terminator("image to window failed", 2);
    }
    data->zoom = 1;
    data->x = 2;
    data->y = 2;
    data->r = 2;
    data->g = 4;
    data->b = 6;
    data->julia_x = 0;
    data->julia_y = 0;
}

void    what_sign(t_data *data, char **av, int ac)
{
    if (!ft_strncmp(av[1], "mandelbrot", 11) && ac == 2)
        data->fract = 1;
    else if (!ft_strncmp(av[1], "julia", 6) && ac == 2)
        data->fract = 2;
    else if (!ft_strncmp(av[1], "julia", 6) && ac == 4)
    {
        data->fract = 2;
        // data->julia_x = ft_atod(av[2]); // check dit nog voor later
        // data->julia_y = ft_atod(av[3]); //check dit nog voor later
    }
    else
        terminator("what yu doin?? use ./fractol [fractal] [r] [i]", 2);
}

// void    parse_av(t_data *data, char *av, int ac)
// {
//     ft_bzero(data, sizeof(t_data));
//     if (ac == 1)
//         terminator("what yu doin?? use ./fractol [fractal]", 2);
//     if (!ft_strncmp(av[1], "mandelbrot", 11) && ac == 2)
//         data->fract = 1;
//     else if (!ft_strncmp(av[1], "julia", 6) && ac == 4)
//         data->fract = 2;
//     else
//         terminator("what yu doin?? use ./fractol [fractal]", 2);
    
// }


