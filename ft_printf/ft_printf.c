/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 13:53:19 by qtrinh        #+#    #+#                 */
/*   Updated: 2022/12/08 13:36:23 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	what_format(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += print_char(va_arg(args, int));
	else if (format == 's')
		print_length += print_str(va_arg(args, char *));
	else if (format == 'p')
		print_length += print_pointer(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		print_length += print_num(va_arg(args, int));
	else if (format == 'u')
		print_length += print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
	{
		print_length += 1;
		print_char('%');
	}
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_len;
	int		i;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += what_format(args, str[i + 1]);
			i++;
		}
		else
			print_len += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}
