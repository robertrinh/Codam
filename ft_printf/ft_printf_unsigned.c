/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_unsigned.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 15:03:07 by qtrinh        #+#    #+#                 */
/*   Updated: 2022/12/07 15:39:07 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen(unsigned int num)
{
	int	length;

	length = 0;
	while (num > 0)
	{
		num = num / 10;
		length++;
	}
	return (length);
}

static char	*itoa_unsigned(unsigned int num)
{
	char	*result;
	int		size;

	size = numlen(num);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size] = '\0';
	// if (num == 0)
	// {
	// 	result[0] = '0';
	// 	return (result);
	// }
	while (num)
	{
		result[size - 1] = num % 10 + '0';
		num = num / 10;
		size--;
	}
	return (result);
}

int	print_unsigned(unsigned int num)
{
	int		char_count;
	char	*str;

	char_count = 0;
	if (num == 0)
		char_count += print_char('0');
	else
	{
		str = itoa_unsigned(num);
		char_count += print_str(str);
		free (str);
	}
	return (char_count);
}
