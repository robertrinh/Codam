/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 14:26:05 by qtrinh        #+#    #+#                 */
/*   Updated: 2022/12/08 15:09:53 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "./Libft/libft.h"
#include "limits.h"

int	main(void)
{
	/* c format */
	char a = 'a';
	char b = '\0';
	/* s format */
	char str[] = "banh cuon";
	char *p = NULL;
	/* dividing tests */
	char str2[] = "---------------------";
	/* hex format */
	unsigned int value = -14;
	/* p format */
	int s = 0;
	int *ptr = &s;

	ft_printf("%s \n", str2);
	ft_printf("Our char: %c\n", a);
	printf("dem mans char: %c\n", a);
	/* divider */
	ft_printf("%s \n", str2);
	ft_printf("Our null-terminator: %c\n", b);
	printf("dem mans null-terminator: %c\n", b);
	/* divider */
	ft_printf("%s \n", str2);
	ft_printf("Our String: %s \n",str);
	printf("dem mans string: %s \n", str);
	/* divider */
	ft_printf("%s \n", str2);
	ft_printf("Our NULL string:%s \n", p);
	printf("dem mans NULL string:%s \n", p);
	/* divider */
	ft_printf("%s \n", str2);
	ft_printf("Our prozent: %%\n");
	printf("dem mans prozent: %%\n");
	/* divider */
	ft_printf("%s \n", str2);
	ft_printf("Decimal value: %d \n", value);
	ft_printf("Our hexa Smoll: %x \n", value);
	ft_printf("Our hexa Big: %X \n", value);
	printf("dem hexa smoll: %x \n", value);
	printf("dem hexa big: %X\n", value);
	/* divider */
	ft_printf("%s \n", str2);
	ft_printf("Our percentage: %%\n");
	printf("dem mans procent: %%\n");
	/* divider */
	ft_printf("%s \n", str2);
	ft_printf("Our ptr address: %p, value is %d \n", ptr, *ptr);
	printf("dem mans ptr address: %p, value is %d \n", ptr, *ptr);
	/* divider */
	ft_printf("%s \n", str2);
	ft_printf("oaaa% \n");
	printf("oaaa% \n");
	/* divider */
	ft_printf("%s \n", str2);
	ft_printf("%%% \n");
	printf("%%% \n");
	/* divider */
	ft_printf("%s \n", str2);	
	printf(" ya pakeuwtest %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" own pakeuwtest %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	return (0);
}
