#include <stdlib.h>
#include <string.h>
// #include "ft_list.h" see the struct needed below

typedef struct t_list
{
	void *data;
	struct t_list *next;
} t_list;

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*current;
	t_list	*previous;
	t_list	*temp;

	previous = NULL;
	current = *begin_list;
	while (current)
	{
		if ((*cmp)(current->data, data_ref) == 0)
		{
			temp = current->next;
			free(current);
			if (previous == NULL)  // Removing the first node
				*begin_list = temp;
			else
				previous->next = temp;
			current = temp; // Move to the next node without updating previous
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
}


#include <stdio.h>
t_list *create_elem(void *data)
{
    t_list *new = malloc(sizeof(t_list));
    if (!new)
        return NULL;
    new->data = data;
    new->next = NULL;
    return new;
}

void print_list(t_list *list)
{
    while (list)
    {
        printf("%s -> ", (char *)list->data);
        list = list->next;
    }
    printf("NULL\n");
}

void list_push_back(t_list **begin_list, void *data)
{
    t_list *new = create_elem(data);
    t_list *temp = *begin_list;

    if (!new)
        return;
    if (!*begin_list)
    {
        *begin_list = new;
        return;
    }
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}

int cmp(void *a, void *b)
{
    return strcmp((char *)a, (char *)b);
}

int main(int argc, char **argv)
{
    t_list *list = NULL;
    char *data_ref = argv[1];
	int i = 2;

    if (argc < 3)
    {
        printf("Usage: %s <data_ref> <list elements>...\n", argv[0]);
        return 1;
    }
	while (i < argc)
	{
        list_push_back(&list, argv[i]);
		i++;
	}
    printf("Original list:\n");
    print_list(list);
    ft_list_remove_if(&list, data_ref, cmp);
    printf("List after removing \"%s\":\n", data_ref);
    print_list(list);
    return (0);
}
