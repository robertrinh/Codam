# ft_printf 🖨️

This project is to discover a popular and versatile C function: ```printf()```. 

All programmers basically know of the function `printf()`. But how does it work? This project let us learn how the printf is coded and it helps us understand the logic behind using ```variadic functions``` in C.

## Function

```ft_printf```

The prototype of `ft_printf()` is:

```c
int	ft_printf(const char *str, ...);
```

Parameters:\
The first argument has to be a string of characters. Afterwards, optional parameters can be given, which is defined by several possible format specifiers.

Return value:\
	`ft_printf` returns the number of written characters represented as an integer. The number does not include the null-terminator (`'\0'`).
	
Format specifiers:
- ```%c``` Prints a single character.
- ```%s``` Prints a string (as defined by the common C convention).
- ```%p``` The void * pointer argument has to be printed in hexadecimal format.
- ```%d``` Prints a decimal (base 10) number.
- ```%i``` Prints an integer in base 10.
- ```%u``` Prints an unsigned decimal (base 10) number.
- ```%x``` Prints a number in hexadecimal (base 16) lowercase format.
- ```%X``` Prints a number in hexadecimal (base 16) uppercase format.
- ```%%``` Prints a percent sign.

## Usage
1. Clone the repository or download the source code files.
2. Compile the files using `make` with the provided `Makefile`
3. Write out a `main.c` file where you can use the `ft_printf`. It's pretty handy to use the original `printf()` to see if it gives the same result 😄
