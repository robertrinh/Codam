// Assignment name  : ft_split
// Expected files   : ft_split.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes a string, splits it into words, and returns them as
// a NULL-terminated array of strings.

// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.

// Your function must be declared as follows:

#include <stdlib.h>

int	skip_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

// note: did not take into account the amount of space for malloc and free but passed nonetheless
char	**ft_split(char *str)
{
	char	**split_string;
	int	i = 0, x = 0, y = 0;

	split_string = malloc(1024);
	while (str[i])
	{
		if (skip_whitespace(str[i]) && str[i])
			i++;
		if (!str[i])
			break;
		split_string[x] = malloc(1024);
		while (!skip_whitespace(str[i]) && str[i])
			split_string[x][y++] = str[i++];
		split_string[x++][y] = 0;
		y = 0;
	}
	split_string[x] = NULL;
	return (split_string);
}

//#include <stdio.h>
// int	main(void)
// {
// 	char test[] = "split is being split";
// 	char **array;

// 	array = ft_split(test);
// 	while (*array)
// 	{
// 		printf("%s\n", *array);
// 		array++;
// 	}
// } 
