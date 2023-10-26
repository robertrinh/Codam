/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 16:10:50 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/10/26 16:35:16 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdbool.h>
#include "../libft/include/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include <math.h>

# define HEIGHT 1000
# define WIDTH 1000
# define MAX_ITER 50
# define X 0
# define Y 1


/**
 * @brief data struct
 * 
 * @param mlx The MLX42 struct used.
 * @param img The image struct
 * @param fract the fractol that will be chosen
 * @param iter the max number of iterations
 * @param x x[0] = beginning and x[1] end of x-axis
 * @param y y[0] = beginning and y[1] end of y-axis
 * @param julia_x x range of julia struct
 * @param julia_y y range of julia struct
 * 
*/

typedef struct	s_data
{
	mlx_t	*mlx;
	mlx_image_t	*img;
	int	fract;
	int	max;
	double	x[2];
	double	y[2];
	double	julia_x;
	double	julia_y;
	int32_t	r;
	int32_t	g;
	int32_t	b;
}	t_data;

/* generic shi */
void    init_bruv(t_data *data, int ac, char **av);
bool	string_check(char *av);
void    terminator(char *str, t_data *data);

/* mandelbrot */

/* julia */


#endif