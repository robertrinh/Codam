#include "Span.hpp"
#include <iostream>

Span::Span() : _maxSize(100000), _numbers()
{
	std::cout << "\033[1;32mDefault constructor called\033[0m" << std::endl;
}

Span::Span(unsigned int N) : _maxSize(N), _numbers()
{
	std::cout << "\033[1;32mParametered constructor called\033[0m" << std::endl;
}

Span::Span(const Span& src) : _maxSize(src._maxSize), _numbers(src._numbers) 
{
	std::cout << "\033[1;32mCopy constructor called\033[0m" << std::endl;
}

Span& Span::operator=(const Span& src) 
{
	std::cout << "\033[1;30mCopy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
	{
		_maxSize = src._maxSize;
		_numbers = src._numbers; 
	}
    return *this;

}
Span::~Span() 
{
	std::cout << "\033[1;31mDestructor Called\033[0m" << std::endl;
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("The span is full mengggg");
	_numbers.push_back(number);
}

/**
 * @brief Finds the smallest difference (span) between any two numbers in the Span.
 * @details Copies and sorts the numbers, then iterates through adjacent pairs to find the minimum difference.
 * @throws std::runtime_error if there are fewer than 2 numbers stored in the Span.
 * @return The smallest span (difference) between any two stored numbers.
 */
int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers mason... WHAT DO THESE NUMBERS MEAN?!");
	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < tmp.size(); ++i)
	{
		int diff = tmp[i] - tmp[i - 1];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

/**
 * @brief Finds the largest difference (span) between any two numbers in the Span.
 * @details Uses iterator *std::min_element and *std::max_element to find the minimum and maximum values, then returns their difference.
 * @throws std::runtime_error if there are fewer than 2 numbers stored in the Span.
 * @return The largest span (difference) between any two stored numbers.
 */
int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers MASON... what DO THESE NUMBERS MEAN?!");
	int minValue = *std::min_element(_numbers.begin(),_numbers.end());
	int maxValue = *std::max_element(_numbers.begin(),_numbers.end());
	return maxValue - minValue;
}

