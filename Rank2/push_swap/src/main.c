/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 16:16:16 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/23 16:16:16 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //delete

void	leak_check(void)
{
	system("leaks push_swap");
}

void	print_stack(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current != NULL)
	{
		printf("Position: %d, Value: %d\n", current->position, current->value);
		current = current->next;
	}
} //delete
void	new_print(t_node *stack)
{
	t_node	*current;
	
	current = stack;
	while (current != NULL)
	{
		printf("Position: %d, Value: %d AFTER SORT\n", current->position,
				current->value);
		current = current->next;
	}
} //delete
int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc == 1)
		return (0);
	input_check(argc, argv);
	stack_a = stacka_init(argc, argv);
	stack_b = NULL;
	sort(&stack_a, &stack_b);
	new_print(stack_a);
	free_node(&stack_a);
	free_node(&stack_b);
	// atexit(&leak_check);
	return (0);
}
