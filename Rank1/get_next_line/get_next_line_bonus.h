/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 16:34:54 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/02/17 17:00:48 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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