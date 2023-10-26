/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 16:52:40 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/10/26 15:13:06 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief prints error message, exits the program
 * @param str The error message that will be printed
*/
void    terminator(char *str, t_data *data)
{
    ft_putendl_fd(str, STDERR_FILENO);
	if (data->mlx)
	{
		mlx_close_window(data->mlx);
		mlx_terminate(data->mlx);
	}
    exit(EXIT_FAILURE);
}

