#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <cstdlib> //* std::abs

class Span
{
private:
	unsigned int _maxSize;
	std::vector<int> _numbers;
public:
	Span();
	Span(unsigned int N);
	Span(const Span& src);
	Span& operator=(const Span &src);
	~Span();

	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;
	const std::vector<int>& getNumbers() const { return _numbers; }

    /**
     * @brief Adds a range of numbers to the Span using iterators.
     * @tparam InputIt Iterator type.
     * @param first Iterator to the first element in the range.
     * @param last Iterator to one past the last element in the range.
     * @throws std::runtime_error if adding the range would exceed the Span's capacity.
     */
    template <typename InputIt>
    void addNumbers(InputIt first, InputIt last) {
        size_t distance = std::distance(first, last);
        if (_numbers.size() + distance > _maxSize)
            throw std::runtime_error("Adding this range would exceed Span capacity");
        _numbers.insert(_numbers.end(), first, last);
    }
};
