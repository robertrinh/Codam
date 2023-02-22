/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 19:37:53 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/02/22 16:18:06 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

/* single fd */
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	// fd = -1;
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free (line);
	}
	free (line);
	close (fd);
	// system("leaks a.out");
	return (0);
}

/* multiple fd */
// int	main(void)
// {
// 	int		fd;
// 	int		fd1;
// 	int		fd2;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY);
// 	fd1 = open("text2.txt", O_RDONLY);
// 	fd2 = open("text3.txt", O_RDONLY);
// 	line = "\0";
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		if (line == NULL)
// 			free(line);
// 	}
// 	line = "\0";
// 	while (line)
// 	{
// 		line = get_next_line(fd1);
// 		printf("%s", line);
// 		if (line == NULL)
// 			free(line);
// 	}
// 	line = "\0";
// 	while (line)
// 	{
// 		line = get_next_line(fd2);
// 		printf("%s", line);
// 		if (line == NULL)
// 			free(line);
// 	}
// 	free(line);
// 	close(fd);
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
