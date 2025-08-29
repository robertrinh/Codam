#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Try this: ./btc [input.txt]" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange btc;
		btc.loadData("data.csv");
		btc.processInputFile(argv[1]);
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}