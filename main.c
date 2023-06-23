/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 16:16:16 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/06/23 15:22:22 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //delete afterwards

int	main(int argc, char **argv)
{
	const int	argv1 = 1;
	t_node	*a;
	t_node	*b;

	if (argc == 1)
		return (0); //exit_succes needs stdlib.h
	input_check(argc, argv, argv1);
	if (!duplicate_check(argv, argv1)) //correct syntax regarding false bool?
		terminator();
	//a = stacka_init(argv, argv1);
	b = NULL; 
	return (0);	
}

	// t_node	*a;
	// t_node	*b;

	// a = NULL;
	// b = NULL; //stack creation in andere functie zetten?
//digit check via bool? want je checkt gewoon true or false als je naar digit kijkt
// aangezien we heletijd first argument van argv gebruiken om input te checken -> make it a const int? can't change value



/* stappenplan:
1. build stacks
2. build actions
3. hardcore 2/3 digits
4. get the sorting algorithm */