/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/16 16:44:56 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/08/17 15:56:06 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief sorting algorithm that uses bitshifting to sort high amount of numbers
 * @param stack_a stack a used to sort
 * @param stack_b stack b used to push
*/
void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	bit;
	int	len;

	bit = 1;
	while (!already_sorted(stack_a))
	{
		len = lst_len(*stack_a);
		while (len)
		{
			if ((*stack_a)->position & bit)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			len--;
		}
		bit <<= 1;
		while (*stack_b)
			pa(stack_b, stack_a);
	}
}
