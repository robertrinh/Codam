/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 16:31:37 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/02/22 15:48:00 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

static char	*read_line(int fd, char *stash)
{
	int		bytes_read;
	char	temp_string[BUFFER_SIZE + 1];

	bytes_read = 1;
	if (!stash)
		stash = gnl_strdup("");
	while (spot_new_line(stash) == -1 && bytes_read != 0)
	{
		bytes_read = read(fd, temp_string, BUFFER_SIZE);
		if (bytes_read == -1)
			return (gnl_free(stash));
		temp_string[bytes_read] = '\0';
		stash = gnl_strjoin(stash, temp_string);
		if (!stash)
			return (NULL);
	}
	if (stash[0] == '\0')
		return (gnl_free(stash));
	return (stash);
}

static char	*retrieve_line(char *str)
{
	char	*new_line;
	int		len;

	new_line = NULL;
	len = spot_new_line(str);
	if (len == -1)
		return (str);
	str[len + 1] = '\0';
	new_line = gnl_strdup(str);
	free(str);
	return (new_line);
}

static char	*remainder_line(char *str)
{
	char	*new_string;
	int		len;

	new_string = NULL;
	len = spot_new_line(str);
	if (len == -1)
		return (free(str), NULL);
	new_string = gnl_strdup(&str[len + 1]);
	free (str);
	return (new_string);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_line(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = gnl_strdup(stash[fd]);
	stash[fd] = remainder_line(stash[fd]);
	line = retrieve_line(line);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	return (line);
}
