/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 14:57:37 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/24 14:28:22 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_node **stack_a)
{
	if ((*stack_a)->position > (*stack_a)->next->position)
		sa(stack_a);
}

void	sort_3(t_node **stack_a)
{
	int	middle;
	int	last;

	middle = (*stack_a)->next->position;
	last = lst_last(*stack_a)->position;
	if (!already_sorted(stack_a))
	{
		if ((*stack_a)->position > middle && (*stack_a)->position < last)
			sa(stack_a);
		else if ((*stack_a)->position > last && (*stack_a)->position < middle)
			rra(stack_a);
		else if (last > middle && (*stack_a)->position > last)
			ra(stack_a);
		else if (middle > last && (*stack_a)->position > middle)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else if ((*stack_a)->position < middle && (*stack_a)->position < last)
		{
			rra(stack_a);
			sa(stack_a);
		}
	}
}

void	sort_4(t_node **stack_a, t_node **stack_b)
{
	int	position;
	
	position = get_position_from_lowest(stack_a);
	if (position == 1)
		sa(stack_a);
	else if (position == 2)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (position == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
}

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int	position;

	position = get_position_from_lowest(stack_a);
	if (position == 1)
		sa(stack_a);
	else if (position == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (position == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (position == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_b, stack_a);
}

/**
 * @brief sorts the numbers in an ascending order through an algorithm.
 * @param stack_a stack a that is used to sort
 * @param stack_b stack b that is used to push numbers
*/
void	sort(t_node **stack_a, t_node **stack_b)
{
	int	len;

	stack_index(*stack_a);
	len = lst_len(*stack_a);
	if (already_sorted(stack_a))
		return ;
	if (len == 2)
		sort_2(stack_a);
	else if (len == 3)
		sort_3(stack_a);
	else if (len == 4)
		sort_4(stack_a, stack_b);
	else if (len == 5)
		sort_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
