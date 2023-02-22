/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 19:37:53 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/02/22 20:05:28 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

void	leak_check(void)
{
	system("leaks a.out");
}
//calls right after exit for leaks

//CALLOC USE

/* single fd */
// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY);
// 	// fd = -1;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	free(line);
// 	close(fd);
// 	atexit(&leak_check);
// 	return (0);
// }

/* multiple fd */
int	main(void)
{
	int		fd;
	int		fd1;
	int		fd2;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	fd1 = open("text2.txt", O_RDONLY);
	fd2 = open("text3.txt", O_RDONLY);
	line = "\0";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			free(line);
		printf("%s \n", line);
		line = get_next_line(fd1);
		if (line)
			free(line);
		printf("%s \n", line);
		line = get_next_line(fd2);
		if (line)
			free(line);
		printf("%s \n", line);
	}
	free(line);
	close(fd);
	close(fd1);
	close(fd2);
	atexit(&leak_check);
	return (0);
}
