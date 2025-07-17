#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime> 

int main() 
{
	std::cout << "Basic test" << std::endl;
	Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    const std::vector<int>& basicNums = sp.getNumbers();
    auto basicMinIt = std::min_element(basicNums.begin(), basicNums.end());
    auto basicMaxIt = std::max_element(basicNums.begin(), basicNums.end());
    if (basicMinIt != basicNums.end() && basicMaxIt != basicNums.end()) {
        std::cout << "Lowest number: " << *basicMinIt << std::endl;
        std::cout << "Highest number: " << *basicMaxIt << std::endl;
    }
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	std::cout << std::endl << "Testing with 10.000.." << std::endl;
    Span bigSpan(10000);
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::vector<int> randomNumbers(10000);
    for (int i = 0; i < 10000; ++i) {
        randomNumbers[i] = std::rand();
    }
    bigSpan.addNumbers(randomNumbers.begin(), randomNumbers.end());
    std::cout << "Big span shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Big span longest: " << bigSpan.longestSpan() << std::endl;

    try {
		std::cout << std::endl << "testing exception for overfilling:" << std::endl;
        sp.addNumber(42);
    } catch (const std::exception& e) {
        std::cout << "Exception caught (overfill): " << e.what() << std::endl;
    }

    try {
		std::cout << std::endl << "testing exception for not enough numbers:" << std::endl;
        Span emptySpan(2);
        emptySpan.addNumber(1);
        std::cout << emptySpan.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught (not enough numbers): " << e.what() << std::endl;
    }
    return 0;
}
