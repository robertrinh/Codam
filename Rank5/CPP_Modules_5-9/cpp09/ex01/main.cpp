#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Try ./RPN [1 2 +]" << std::endl;
		return 1;
	}
	RPN calculator;
	try
	{
		int result = calculator.rpn_operations(argv[1]);
		std::cout << result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}