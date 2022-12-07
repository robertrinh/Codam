/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 14:26:05 by qtrinh        #+#    #+#                 */
/*   Updated: 2022/12/07 15:27:19 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "./Libft/libft.h"

int	main(void)
{
	char a = 'a';
	char b = '\0';
	char str[] = "banh cuon";
	char str1[] = "";
	char str2[] = "---------------------";
	unsigned int value =  2147483647;
	int x = 50;
	int *ptr = &x;

	ft_printf("%s \n", str2);
	ft_printf("Our char: %c\n", a);
	printf("dem mans char: %c\n", a);
	ft_printf("%s \n", str2);
	ft_printf("Our null: %c\n", b);
	printf("dem mans null: %c\n", b);
	ft_printf("%s \n", str2);
	ft_printf("Our String: %s \n",str);
	printf("dem mans string: %s \n", str);
	ft_printf("%s \n", str2);
	ft_printf("Our empty string:%s \n", str1);
	printf("dem mans empty string:%s \n", str1);
	ft_printf("%s \n", str2);
	ft_printf("Our prozent: %%\n");
	printf("dem mans prozent: %%\n");
	ft_printf("%s \n", str2);
	ft_printf("Decimal value: %d \n", value);
	ft_printf("Our hexa Smoll: %x \n", value);
	ft_printf("Our hexa Big: %X \n", value);
	printf("dem hexa smoll: %x \n", value);
	printf("dem hexa big: %X\n", value);
	ft_printf("%s \n", str2);
	ft_printf("Our percentage: %%\n");
	printf("dem mans procent: %%\n");
	ft_printf("%s \n", str2);
	ft_printf("Our ptr address: %p, value is %d \n", ptr, *ptr);
	printf("dem mans ptr address: %p, value is %d \n", ptr, *ptr);
	return (0);
}