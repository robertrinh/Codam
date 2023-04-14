/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   help.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 11:42:10 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/04/13 15:42:06 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handler(char *error_msg, t_pipex *pipex)
{
	free(pipex);
	perror(error_msg);
	exit(EXIT_FAILURE);
}

t_pipex	*pepe_init(void)
{
	t_pipex *pipex;
	pipex = ft_calloc(sizeof(t_pipex), 1);
	//je kan waardes nog erinzetten
	//ook voor argc/argv als je dat nog wilt gebruiken
	return (pipex);
}

