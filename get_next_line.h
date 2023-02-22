/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/21 11:05:33 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/02/22 14:50:49 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char		*get_next_line(int fd);
size_t		gnl_strlen(char const *str);
char		*gnl_strdup(char const *s1);
char		*gnl_strjoin(char *s1, char *s2);
void		*gnl_free(char *str);
ssize_t		spot_new_line(char *str);

#endif