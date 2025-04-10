// Assignment name : brackets Expected files : *.c *.h Allowed functions: write

// Write a program that takes an undefined number of strings in arguments. For each argument, the program prints on the standard output "OK" followed by a newline if the expression is correctly bracketed, otherwise it prints "Error" followed by a newline.

// Symbols considered as 'brackets' are brackets '(' and ')', square brackets '[' and ']'and braces '{' and '}'. Every other symbols are simply ignored.

//     An opening bracket must always be closed by the good closing bracket in the correct order.
//     A string which not contains any bracket is considered as a correctly bracketed string.
//     If there is no arguments, the program must print only a newline.

// Examples :

// $> ./brackets '(johndoe)' | cat -e

// OK$

// $> ./brackets '([)]' | cat -e

// Error$

// $> ./brackets '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}' | cat -e

// OK$

// OK$

// $> ./brackets | cat -e

// $

// $>

#include <unistd.h>

int left_bracket(char c)
{
	if (c == '[' || c == '{' || c == '(')
		return 1;
	return 0;
}

int right_bracket(char c)
{
	if (c == ']' || c == '}' || c == ')')
		return 1;
	return 0;
}

int check_match(char c, char c1)
{
	if ((c == '[' && c1 == ']') || (c == '{' && c1 == '}') || (c == '(' && c1 == ')'))
		return 1;
	return 0;
}

int brackets(char *str)
{
	int i = 0, top = 0;
	int stack[4096];

	if (!str[0])
		return 0;
	while (str[i])
	{
		if (left_bracket(str[i]))
		{
			stack[top] = str[i];
			top++;
		}
		if (right_bracket(str[i]))
		{
			if (top == 0 || !check_match(stack[top - 1], str[i]))
				return 1;
			else
				top--;
		}
		i++;
	}
	if (top != 0)
		return 1;
	else
		return 0;
}

int main(int argc, char **argv)
{
	int i = 1;
	if (argc == 1)
		return(write(1, "\n", 1));
	while (argv[i])
	{
		if (brackets(argv[i]) == 0)
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 7);
		i++;
	}
	return 0;
}