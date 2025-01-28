// Assignment name  : print_hex
// Expected files   : print_hex.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a positive (or zero) number expressed in base 10,
// and displays it in base 16 (lowercase letters) followed by a newline.

// If the number of parameters is not 1, the program displays a newline.

// Examples:

// $> ./print_hex "10" | cat -e
// a$
// $> ./print_hex "255" | cat -e
// ff$
// $> ./print_hex "5156454" | cat -e
// 4eae66$
// $> ./print_hex | cat -e
// $

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

int	atoi_tings(char *str)
{
	int i = 0, res = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

// note: not sure if negative is needed
void	print_hex(int num)
{
	char hex_digits[] = "0123456789abcdef";

	if (num >= 16)
		print_hex(num / 16);
	put_char(hex_digits[num % 16]);
}

int	main(int argc, char **argv)
{
	int num = 0;
	if (argc == 2)
	{
		num = atoi_tings(argv[1]);
		print_hex(num);
	}
	write(1, "\n", 1);
	return (0);
}
