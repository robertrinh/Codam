#include <stdlib.h>

int *ft_range(int start, int end)
{
	int size = 0, i = 0;
	int *array;
	
	if (start <= end)
		size = end - start + 1;
	else
		size = start - end + 1;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	if (start <= end)
	{
		while (i < size)
		{
			array[i] = start + i;
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			array[i] = start - i;
			i++;
		}
	}
	return (array);
}

//TESTER
// #include <stdio.h>
// void print_array(int *arr, int size) {
//     if (arr == NULL) {
//         printf("NULL\n");
//         return;
//     }
//     for (int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int main() 
// {
//     int *arr1 = ft_range(1, 3);
//     if (arr1 != NULL) {
//         print_array(arr1, 3); // Should print: 1 2 3
//         free(arr1);
//     }

//     int *arr2 = ft_range(0, -3);
//     if (arr2 != NULL) {
//         print_array(arr2, 4); // Should print: -3 -2 -1 0 1
//         free(arr2);
//     }

//     int *arr3 = ft_range(0, 0);
//     if (arr3 != NULL) {
//         print_array(arr3, 1); // Should print: 0
//         free(arr3);
//     }

//     int *arr4 = ft_range(5, 3);
//     print_array(arr4, 0); // Should print: NULL

//     return 0;
// }
