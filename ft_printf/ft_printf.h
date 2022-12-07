/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 20:47:24 by robertrinh    #+#    #+#                 */
/*   Updated: 2022/12/02 16:52:26 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char*, ...);
int		print_char(int c);
int		print_str(char *str);
int		print_num(int number);
int		print_unsigned(unsigned int);
int		print_hex(unsigned int num, const char format);
int		print_pointer(unsigned long int num);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

#endif