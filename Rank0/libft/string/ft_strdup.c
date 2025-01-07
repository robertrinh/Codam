/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 16:46:35 by qtrinh        #+#    #+#                 */
/*   Updated: 2024/06/10 15:53:52 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*ptr;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, len + 1);
	return (ptr);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str[] = "choco mint";

	printf("OG %s \n", strdup(str));
	printf("Ours %s \n", ft_strdup(str));
} */