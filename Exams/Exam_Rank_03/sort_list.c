// Assignment name  : sort_list
// Expected files   : sort_list.c
// Allowed functions: 
// --------------------------------------------------------------------------------

// Write the following functions:

// t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

// This function must sort the list given as a parameter, using the function 
// pointer cmp to select the order to apply, and returns a pointer to the 
// first element of the sorted list.

// Duplications must remain.

// Inputs will always be consistent.

// You must use the type t_list described in the file list.h 
// that is provided to you. You must include that file 
// (#include "list.h"), but you must not turn it in. We will use our own 
// to compile your assignment.

// Functions passed as cmp will always return a value different from 
// 0 if a and b are in the right order, 0 otherwise.

#include <stdio.h>

typedef struct s_list
{
	int	data;
	struct s_list	*next;
}	t_list;
// normally this would be the header (if I recall correctly)

t_list		*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*head;
	int		temp;

	head = lst;
	while (lst->next)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			if (lst->data == lst->next->data)
			{
				lst = lst->next;
				continue ;
			}
			temp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = temp;
			lst = head;
		}
		else
			lst = lst->next;
	}
	lst = head;
	return (lst);
}

// testing
#include <stdlib.h>
t_list	*new_node(int data)
{
	t_list *node = malloc(sizeof(t_list));
	node->data = data;
	node->next = NULL;
	return (node);
}

int ascending(int a, int b)
{
	return (a < b);
}

int descending(int a, int b)
{
	return (a > b);
}

void print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d -> ", lst->data);
		lst = lst->next;
	}
	printf("NULL\n");
}

int main(void)
{
	t_list *a = new_node(8);
	t_list *b = new_node(3);
	t_list *c = new_node(1);
	t_list *d = new_node(2);
	t_list *e = new_node(1);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;

	printf("Before sorting:\n");
	print_list(a);
	a = sort_list(a, descending); // swap with ascending for double check
	printf("After sorting:\n");
	print_list(a);
	return (0);
}