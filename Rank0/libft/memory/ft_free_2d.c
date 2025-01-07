/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_2d.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/16 17:20:20 by robertrinh    #+#    #+#                 */
/*   Updated: 2024/06/10 15:52:53 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_2d(char **two_d_array)
{
	size_t	i;

	i = 0;
	while (two_d_array[i])
	{
		free(two_d_array[i]);
		two_d_array[i] = NULL;
		i++;
	}
	free(two_d_array);
	return (NULL);
}
