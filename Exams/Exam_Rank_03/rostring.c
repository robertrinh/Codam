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
        if (!ft_isblank(s[i]) && (i == 0 || ft_isblank(s[i - 1])))
        {
            if (word) 
				write(1, " ", 1);
            while (s[i] && !ft_isblank(s[i]))
                write(1, &s[i++], 1);
            word = 1;
        }
        else i++;
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

