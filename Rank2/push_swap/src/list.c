/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 15:16:27 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/17 16:09:02 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* initialises a new node */
t_node	*new_node(int value)
{
	t_node	*newnode;

	newnode = ft_calloc(1, sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->value = value;
	newnode->position = 0;
	newnode->next = NULL;
	return (newnode);
}

/* returns last node of the list */
t_node	*lst_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* adds node at the end of the linked list */
void	add_lst_at_end(t_node **lst, int value)
{
	t_node	*new;
	t_node	*current;

	if (*lst == NULL)
	{
		*lst = new_node(value);
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	new = new_node(value);
	current->next = new;
}

/* counts number of nodes in list */
int	lst_len(t_node *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
