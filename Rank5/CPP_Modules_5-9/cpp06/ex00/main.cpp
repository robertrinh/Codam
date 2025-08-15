#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}

// int main(void)
// {
// 	{
// 	std::cout << "\n=== Character Tests ===" << std::endl;
// 	std::cout << "\033[1;34mtesting a\033[0m" << std::endl;
// 	ScalarConverter::convert("a");  //* regular character
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting spacebar \033[0m" << std::endl;
// 	ScalarConverter::convert(" ");  //* space character
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting @\033[0m" << std::endl;
// 	ScalarConverter::convert("@");  //* special character
// 	std::cout << std::endl;
// 	}
// 	{
// 	std::cout << "\n=== Integer Tests ===" << std::endl;
// 	std::cout << "\033[1;34mtesting 0\033[0m" << std::endl;
// 	ScalarConverter::convert("0");     //* zero
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting 42\033[0m" << std::endl;
// 	ScalarConverter::convert("42");    //* positive integer
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting -42\033[0m" << std::endl;
// 	ScalarConverter::convert("-42");   //* negative integer
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting 2147483647\033[0m" << std::endl;
// 	ScalarConverter::convert("2147483647");  //* int_max
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting -2147483648\033[0m" << std::endl;
// 	ScalarConverter::convert("-2147483648"); //* int_min
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting 2147483648\033[0m" << std::endl;
// 	ScalarConverter::convert("2147483648");  //* int_max + 1
// 	std::cout << std::endl;
// 	}
// 	{
// 	std::cout << "\n=== Float Tests ===" << std::endl;
// 	std::cout << "\033[1;34mtesting 0.0f\033[0m" << std::endl;
// 	ScalarConverter::convert("0.0f");      //* zero float
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting 42.0f\033[0m" << std::endl;
// 	ScalarConverter::convert("42.0f");     //* positive float
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting -42.0f\033[0m" << std::endl;
// 	ScalarConverter::convert("-42.0f");    //* negative float
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting 42.42f\033[0m" << std::endl;
// 	ScalarConverter::convert("42.42f");    //* decimal float
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting nanf\033[0m" << std::endl;
// 	ScalarConverter::convert("nanf");      //* nan
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting +inff\033[0m" << std::endl;
// 	ScalarConverter::convert("+inff");     //* positive infinity
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting -inff\033[0m" << std::endl;
// 	ScalarConverter::convert("-inff");     //* negative infinity
// 	std::cout << std::endl;
// 	}
// 	{
// 	std::cout << "\n=== Double Tests ===" << std::endl;
// 	std::cout << "\033[1;34mtesting 0.0\033[0m" << std::endl;
// 	ScalarConverter::convert("0.0");       //* zero double
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting 42.0\033[0m" << std::endl;
// 	ScalarConverter::convert("42.0");      //* positive double
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting -42.0\033[0m" << std::endl;
// 	ScalarConverter::convert("-42.0");     //* negative double
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting 42.42\033[0m" << std::endl;
// 	ScalarConverter::convert("42.42");     //* decimal double
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting nan\033[0m" << std::endl;
// 	ScalarConverter::convert("nan");       //* nan
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting +inf\033[0m" << std::endl;
// 	ScalarConverter::convert("+inf");      //* positive infinity
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting -inf\033[0m" << std::endl;
// 	ScalarConverter::convert("-inf");      //* negative infinity
// 	std::cout << std::endl;
// 	}
// 	{
// 	std::cout << "\n=== Invalid Tests ===" << std::endl;
// 	std::cout << "\033[1;34mtesting empty string\033[0m" << std::endl;
// 	ScalarConverter::convert("");          //* empty string
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting abc\033[0m" << std::endl;
// 	ScalarConverter::convert("abc");       //* invalid string
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting 42.42.42\033[0m" << std::endl;
// 	ScalarConverter::convert("42.42.42");  //* invalid number
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting 42.f\033[0m" << std::endl;
// 	ScalarConverter::convert("42.f");      //* invalid float (missing decimal)
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting 42.0ff\033[0m" << std::endl;
// 	ScalarConverter::convert("42.0ff");    //* invalid float (double f)
// 	std::cout << std::endl;
// 	std::cout << "\033[1;34mtesting 42.0.0\033[0m" << std::endl;
// 	ScalarConverter::convert("42.0.0");    //* invalid double (double decimal)
// 	std::cout << std::endl;
// 	}
// 	return (0);
// }

