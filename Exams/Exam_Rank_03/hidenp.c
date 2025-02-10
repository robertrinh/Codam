// Assignment name  : hidenp
// Expected files   : hidenp.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays 1 with a newline.
// if the string is hidden in the second string and will display 0 with a newline
// if the first string is not found in the second string

// The order has the be the same, and an empty string is hidden in any string.
// Examples:

// $> ./hidenp "abc" "fjsppalkjqqb182c"| cat -e
// 1$
// $> ./hidenp "llo" "helllo" | cat -e
// 1$
// $> ./hidenp "abc" "btarc" | cat -e
// 0$
// $> ./hidenp | cat -e
// $

#include <unistd.h>

void	hidenp(char *s1, char *s2)
{
	int	i = 0, j = 0;

	while (s1[i])
	{
		while (s2[j] && s2[j] != s1[i]) // check each char of s2 until s1[i] is found
			j++;
		if (!s2[j]) // no s1 found in s2 at the end
		{
			write(1, "0\n", 2);
			return ;
		}
		i++; //char found, onto the next one
		j++; //check the next one in the string
	}
	write(1, "1\n", 2);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	else
		write(1, "\n", 1);
	return (0);
}
