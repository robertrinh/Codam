// Assignment name  : rostring
// Expected files   : rostring.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays this string after rotating it
// one word to the left.

// Thus, the first word becomes the last, and others stay in the same order.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.

// Words will be separated by only one space in the output.

// If there's less than one argument, the program displays \n.

// Example:

// $>./rostring "abc   " | cat -e
// abc$
// $>
// $>./rostring "Que la      lumiere soit et la lumiere fut"
// la lumiere soit et la lumiere fut Que
// $>
// $>./rostring "     AkjhZ zLKIJz , 23y"
// zLKIJz , 23y AkjhZ
// $>
// $>./rostring | cat -e
// $
// $>

#include <unistd.h>
#include <stdlib.h>

int ft_isblank(char c)
{
	return (c == ' ' || c == '\t');
}

void rostring(char *s)
{
    int i = 0, first = 0, len = 0, word = 0;
    
	//skip first whitespace
    while (ft_isblank(s[i])) 
		i++;
	
	// mark first word
    first = i;
    while (s[i] && !ft_isblank(s[i])) 
	{ 
		i++; 
		len++; 
	}
    
	//skip whitespace after first word
    while (ft_isblank(s[i])) 
		i++;
    
	// write the whole string after first word
    while (s[i])
    {
        if (!ft_isblank(s[i]) && ft_isblank(s[i - 1]))
        {
            if (word) 
				write(1, " ", 1);
            while (s[i] && !ft_isblank(s[i]))
                write(1, &s[i++], 1);
            word = 1;
        }
        else 
			i++;
    }
    
	//write first word
    if (len > 0)
    {
		if (word) 
			write(1, " ", 1);
        write(1, &s[first], len);
    }
}

int main(int argc, char **argv)
{
	if (argc == 2)
		rostring(argv[1]);
	write(1, "\n", 1);
	return 0;
}

