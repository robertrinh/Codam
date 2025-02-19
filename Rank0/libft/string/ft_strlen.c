/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:45:31 by qtrinh        #+#    #+#                 */
/*   Updated: 2024/06/10 15:54:36 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/* #include <stdio.h>
#include <string.h>
int main(void)
{
    char    str[] = "test";

    printf("OG: %lu\n", strlen(str));
    printf("mine: %%zu\n", ft_strlen(str));
} */