/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_hex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 12:41:57 by qtrinh        #+#    #+#                 */
/*   Updated: 2022/12/07 16:28:42 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_length(int num)
{
	int	length;

	length = 0;
	while (length)
	{
		num = num / 16;
		num++;
	}
	return (length);
}

static void	put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		put_hex(num / 16, format);
		put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			print_char(num + '0');
		else
		{
			if (format == 'x')
				print_char(num % 10 + 'a');
			if (format == 'X')
				print_char(num - 10 + 'A');
		}	
	}
}

int	print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (print_char('0'));
	else
		put_hex(num, format);
	return (hex_length(num));
}
