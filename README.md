# ft_printf

This project is to discover a popular and versatile C function: ```printf()```. This exercise is a great
opportunity to improve programming skills. It is of moderate difficulty and introduces the phenomenon ```variadic functions``` in C.

## Function

```ft_printf```

The prototype is consisted as the following:

```c
int	ft_printf(const char *str, ...);
```

> Parameters of the string:
The first argument has to be a string of characters. Afterwards, optional parameters can be given, which is defined by several possible format specifiers.

> Return value:
	ft_printf returns the number of written characters in an integer. The number does not include the null-terminator ('\0').
	
> Format specifiers:\
```%c``` Prints a single character.\
```%s``` Prints a string (as defined by the common C convention).\
```%p``` The void * pointer argument has to be printed in hexadecimal format.\
```%d``` Prints a decimal (base 10) number.\
```%i``` Prints an integer in base 10.\
```%u``` Prints an unsigned decimal (base 10) number.\
```%x``` Prints a number in hexadecimal (base 16) lowercase format.\
```%X``` Prints a number in hexadecimal (base 16) uppercase format.\
```%%``` Prints a percent sign.\
