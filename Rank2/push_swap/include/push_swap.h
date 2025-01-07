/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 16:16:19 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/08/21 16:22:38 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* malloc, free, bool */
# include <stdbool.h>
# include <stdlib.h>

/* libft */
# include "../libft/include/libft.h"

typedef struct s_node
{
	int				value;
	int				position;
	struct s_node	*next;
}					t_node;

/* parsing */
int					main(int argc, char **argv);
void				terminator(void);
void				input_check(int argc, char **argv);
t_node				*stacka_init(int argc, char **argv);
void				stack_index(t_node *stack);

/* sort */
bool				already_sorted(t_node **stack_a);
void				sort(t_node **stack_a, t_node **stack_b);
int					find_lowest_index(t_node **stack_a);
int					get_position(t_node **stack_a);
void				radix_sort(t_node **stack_a, t_node **stack_b);

/* linked list */
t_node				*new_node(int value);
t_node				*lst_last(t_node *lst);
int					lst_len(t_node *lst);
void				add_lst_at_end(t_node **lst, int value);
void				free_node(t_node **node);

/* actions */
void				pa(t_node **stack_b, t_node **stack_a);
void				pb(t_node **stack_a, t_node **stack_b);
void				ra(t_node **stack_a);
void				rb(t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);
void				rra(t_node **stack_a);
void				rrb(t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);
void				sa(t_node **stack_a);
void				sb(t_node **stack_b);
void				ss(t_node **stack_a, t_node **stack_b);

void				print_stack(t_node *stack_a);

#endif