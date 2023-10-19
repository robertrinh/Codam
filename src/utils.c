/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/30 16:52:40 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/09/14 15:03:50 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief prints error message, exits the program
 * @param str The error message that will be printed
*/
void    terminator(char *str, int fd)
{
    ft_putendl_fd(str, STDERR_FILENO);
    exit(EXIT_FAILURE);
}
