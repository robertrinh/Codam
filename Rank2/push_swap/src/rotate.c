/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/14 15:37:01 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/17 17:02:55 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Shift up all elements of a stack by 1. 
 * The first element becomes the last one.
 * @param stack the stack used to rotate
*/
static void	rotate(t_node **stack)
{
	t_node	*temp;
	t_node	*lastnode;

	if (!*stack || !(*stack)->next) //!(*stack) is empty stack, !(*stack)->next is stack with one element
		return ;
	temp = (*stack)->next; //finding last element of stack
	lastnode = *stack; //assign current value of stack to lastnode
	temp = lst_last(*stack); //find last node in linked list, assign to temp
	temp->next = *stack; //connect last element to the first element to complete circle
	*stack = (*stack)->next; //update stack pointer to the next element (the actual shifting)
	lastnode->next = NULL; //break cycle by setting next pointer to NULL (from the old value of stack)
}

/* Shift up all elements of stack a by 1.
The first element becomes the last one */
void	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

/* Shift up all elements of stack b by 1.
The first element becomes the last one */
void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

/* execute ra and b at the same time */
void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
