/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 14:31:54 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/17 17:03:17 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Take first element at top of first stack, 
 * put it at top of receiving stack. 
 * Do nothing if other stack is empty.
 * @param stack_send the stack to send to
 * @param stack_receive stack to receive
*/
void	push(t_node **stack_send, t_node **stack_receive)
{
	t_node	*temp;

	if (!stack_send || !(*stack_send)) //check if stack_send is empty or not init
		return ;
	temp = *stack_send; //store top of first stack in temp
	*stack_send = (*stack_send)->next; //Update the top of stack 1 to point to the next node (remove the top node)
	if (!stack_receive)
		*stack_receive = temp; //if no stack top 2, update top of stack 2 to temporary node
	else
	{
		temp->next = *stack_receive; //set next pointer of temp node to point to stack top 2
		*stack_receive = temp; //update top of stack 2 to temp node
	}
}

/* Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */
void	pa(t_node **stack_b, t_node **stack_a)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

/* Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty */
void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
