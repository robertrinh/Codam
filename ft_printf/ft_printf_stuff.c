/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_stuff.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 21:24:37 by robertrinh    #+#    #+#                 */
/*   Updated: 2022/12/07 15:48:40 by qtrinh        ########   odam.nl         */
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
	int	count;
	
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6); //returnt bytes
	}
	count = ft_strlen(str);
	write(1, str, count);
	return (count);
}

int	print_num(int num)
{
	int		i;
	int		str_len;
	char	*str;

	i = 0;
	str = ft_itoa(num);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	str_len = ft_strlen(str);
	free (str);
	return (str_len);
}

static int	numlen(long int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length++;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

/* DONT FORGET TO DELETE AFTERWARDS */
char	*ft_itoa(int n)
{
	int			size;
	char		*result;
	long int	i;

	i = n;
	size = numlen(i);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	if (i == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (i < 0)
		i *= -1;
	while (size--)
	{
		result[size] = i % 10 + '0';
		i = i / 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
