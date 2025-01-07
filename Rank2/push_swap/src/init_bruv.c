/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_bruv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 17:36:59 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/21 16:14:37 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_index(t_node *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack;
	temp = stack;
	while (current)
	{
		while (temp)
		{
			if (current->value < temp->value)
				temp->position++;
			temp = temp->next;
		}
		temp = stack;
		current = current->next;
	}
}



t_node	*stacka_init(int argc, char **argv)
{
	t_node	*stack_a;
	int		i;
	char	**temp;

	i = 0;
	stack_a = NULL;
	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		if (!temp)
			exit(EXIT_FAILURE);
	}
	else
		temp = argv + 1;
	while (temp[i])
	{
		add_lst_at_end(&stack_a, ft_ayetoi(temp[i]));
		i++;
	}
	if (argc == 2)
		ft_free_2d(temp);
	return (stack_a);
}
