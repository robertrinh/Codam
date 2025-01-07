/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 16:07:07 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/24 14:28:01 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	terminator(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

bool	already_sorted(t_node **stack_a)
{
	t_node	*temp;

	temp = *stack_a;
	while (temp && temp->next)
	{
		if (temp->position > temp->next->position)
			return (false);
		temp = temp->next;
	}
	return (true);
}
/**
 * @brief gets position which is x nodes away from lowest index
 * @param stack stack used
*/
int	get_position_from_lowest(t_node **stack_a)
{
	int	i;
	int	lowest;
	t_node	*temp;

	i = 0;
	temp = *stack_a;
	while (temp)
	{
		lowest = find_lowest_index(stack_a);
		if (temp->position == lowest)
			break ;
		temp = temp->next;
		i++;
	}
	return (i);
}

int	find_lowest_index(t_node **stack_a)
{
	int		lowest_index;
	t_node	*node;

	node = *stack_a;
	lowest_index = node->position; //DIT IS HET!!!
	while (node)
	{
		if (node->position < lowest_index)
			lowest_index = node->position;
		node = node->next;
	}
	return (lowest_index);
}

void	free_node(t_node **node)
{
	t_node	*temp;

	while (*node)
	{
		temp = *node;
		*node = (*node)->next;
		if (temp)
			free (temp);
	}
}
