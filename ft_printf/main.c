/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 14:26:05 by qtrinh        #+#    #+#                 */
/*   Updated: 2022/12/14 17:59:41 by qtrinh        ########   odam.nl         */
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
	/* d/i format */
	int i = 1101100;
	/* u format */
	unsigned int value = 4294967295;
	unsigned int neg_val = -1;
	/* hex format */
	unsigned int hex_value = 311294;
	/* p format */
	int s = 0;
	int *ptr = &s;
	/* dividing tests */
	char str2[] = "---------------------";

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
	ft_printf("our digit: %d \n", i);
	printf("dem mans digit: %d \n", i);
	ft_printf("our integer: %i \n", i);
	printf("dem mans integer: %i \n", i);
	/* divider */
	ft_printf("%s \n", str2);
	ft_printf("Our prozent: %%\n");
	printf("dem mans prozent: %%\n");
	/* divider */
	ft_printf("%s \n", str2);
	ft_printf("Our uint: %u \n", value);
	printf("dem uint: %u \n", value);
	ft_printf("our neg uint: %u \n", neg_val);
	printf("dem neg uint: %u \n", neg_val);
	/* divider */
	ft_printf("%s \n", str2);
	ft_printf("Decimal value: %d \n", hex_value);
	ft_printf("Our hexa Smoll: %x \n", hex_value);
	ft_printf("Our hexa Big: %X \n", hex_value);
	printf("dem hexa smoll: %x \n", hex_value);
	printf("dem hexa big: %X\n", hex_value);
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
	ft_printf("Ours oaaa% \n");
	printf("OG oaaa% \n");
	/* divider */
	ft_printf("%s \n", str2);	
	printf("francinette test: %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("francinette test: %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	/* divider */
	ft_printf("%s \n", str2);
	ft_printf("our random: adsfklj%%%%i%fss\n");
	printf("random: adsfklj%%%%i%fss\n");
	/* divider */
	ft_printf("%s \n", str2);
	int ft_len = ft_printf("%%%k");
	printf("\n");
	int og_len = printf("%%%k");
	printf("\n");
	if (ft_len == og_len)
		printf("GOOD");
	else
		printf("BAD");
	return (0);
}
