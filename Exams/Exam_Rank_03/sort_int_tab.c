// Assignment name  : sort_int_tab
// Expected files   : sort_int_tab.c
// Allowed functions: 
// --------------------------------------------------------------------------------

// Write the following function:

// void sort_int_tab(int *tab, unsigned int size);

// It must sort (in-place) the 'tab' int array, that contains exactly 'size'
// members, in ascending order.

// Doubles must be preserved.

// Input is always coherent.

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	int temp = 0;
	
	if (size < 2)
	return ;
	while (i < size - 1) // -1 because last pass would be redundant
	{
		unsigned int j = 0;
		while (j < size - 1 - i) // -i to avoid rechecking sorted elements
		{
			if (tab[j] > tab[j + 1]) //bubble sort
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

//TESTER
#include <stdio.h>
int main(void)
{
	int arr[] = {5, 3, 8, -1, 2, 7, 4, 6};
	unsigned int size = 8, i = 0;

	printf("Before sorting: ");
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	sort_int_tab(arr, size);
	printf("After sorting:  ");
	i = 0;
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	return 0;
}
