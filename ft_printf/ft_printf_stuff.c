/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_stuff.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 21:24:37 by robertrinh    #+#    #+#                 */
/*   Updated: 2022/12/08 14:41:38 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./Libft/libft.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	int	str_len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	str_len = ft_strlen(str);
	write(1, str, str_len);
	return (str_len);
}

int	print_num(int num)
{
	int		count;
	char	*str;

	str = ft_itoa(num);
	count = ft_strlen(str);
	write(1, str, count);
	free (str);
	return (count);
}
