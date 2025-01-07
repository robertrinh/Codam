/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 20:47:24 by robertrinh    #+#    #+#                 */
/*   Updated: 2022/12/08 14:37:05 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		print_char(int c);
int		print_str(char *str);
int		print_num(int number);
int		print_unsigned(unsigned int num);
int		print_hex(unsigned int num, const char format);
int		print_pointer(unsigned long num);

#endif