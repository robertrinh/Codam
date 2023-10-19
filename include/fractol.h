/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 16:10:50 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/09/21 14:14:26 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdbool.h>
#include "../libft/include/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include <math.h>

# define HEIGHT 1100
# define WIDTH 1100
# define MAX_ITER 50


/**
 * @brief data struct
 * 
 * @param mlx The MLX41 struct used.
 * @param img The image struct
 * @param fract the fractol that will be chosen
 * @param iter the max number of iterations
 * @param x struct that has the x range
 * @param y struct that has the y range
 * @param julia_x x range of julia struct
 * @param julia_y y range of julia struct
 * 
*/

typedef struct	s_data
{
	mlx_t	*mlx;
	mlx_image_t	*img;
	int	fract;
	int	iter;
	double	x;
	double	y;
	double	julia_x;
	double	julia_y;
	int32_t	r;
	int32_t	g;
	int32_t	b;
	float	zoom;
}	t_data;

/* generic shi */
void    init_bruv(t_data *data);
void    terminator(char *str, int fd);

/* mandelbrot */

/* julia */


#endif