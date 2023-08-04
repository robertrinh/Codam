/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/14 15:38:30 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/02 15:42:48 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  Swap the first 2 elements at the top of stack.
Do nothing if there is only one or no elements.*/
static void	swap(t_node **stack)
{
	t_node	*temp;

	if (!*stack || !(*stack)->next) //check if the stack is NULL / pointer of the first node is NULL aka stack with one element
		return ;
	temp = (*stack)->next; // save address of second node to temp
	(*stack)->next = temp->next; //update next pointer of first node to skip second node
	temp->next = *stack; //set next pointer of second node to first node
	*stack = temp; //Update the stack pointer to point to the second node
}
void	sa(t_node **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}
void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
