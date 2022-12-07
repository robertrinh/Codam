/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_pointer.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 15:46:24 by qtrinh        #+#    #+#                 */
/*   Updated: 2022/12/02 17:07:47 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_hex_length(unsigned long num)
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

static void	ptr_hex(unsigned long num)
{
	if (num >= 16)
	{
		ptr_hex(num / 16);
		ptr_hex(num % 16);
	}
	else
	{
		if (num <= 9)
			print_char(num + '0');
		else
			print_char(num - 10 + 'a');
	}
}

int	print_pointer(unsigned long ptr)
{
	int	length;

	length = 0;
	length += write(1, "0x", 2);
	if (ptr == 0)
		length += print_char('0');
	else
	{
		ptr_hex(ptr);
		length += ptr_hex_length(ptr);
	}
	return (length);
}
