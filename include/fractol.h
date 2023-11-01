/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 16:10:50 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/11/01 13:28:50 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdbool.h>
# include "../libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>

# define HEIGHT 1000
# define WIDTH 1000
# define MAX_ITER 50

# define X 0
# define Y 1

# define MANDELBROT 1
# define JULIA 2

# define LEFT 0
# define RIGHT 1
# define DOWN 0
# define UP 1

/**
 * @brief data struct
 * 
 * @param mlx The MLX42 struct used.
 * @param img The image struct
 * @param fract the fractol that will be chosen
 * @param x x[0] = left side and x[1] right side of x-axis
 * @param y y[0] = down side and y[1] up side of y-axis
 * @param julia_x x range of julia struct
 * @param julia_y y range of julia struct
 * @param colour the R-G-B colours used to render colours
*/

enum e_colours {r, g, b};

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				fract;
	int				max;
	double			x[2];
	double			y[2];
	double			julia_x;
	double			julia_y;
	enum e_colours	colour[3];
}	t_data;

/* generic shi */
void		init_bruv(t_data *data, int ac, char **av);
void		terminator(char *str, t_data *data);
void		what_fractal(t_data *data);
uint32_t	get_rgba(t_data *data, double iter);
void		init_data(t_data *data);

/* mandelbrot */
void		mandelbrot(t_data *data);

/* julia */
void		julia(t_data *data);

/* hooks */
void		press_keys(mlx_key_data_t keydata, t_data *data);
void		move_x(t_data *data, double amount);
void		move_y(t_data *data, double amount);
void		zoom_in_n_out(double x, double y, t_data *data);

#endif