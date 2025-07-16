#pragma once

#include <stdexcept>

/**
 * @brief dynamic array class template.
 * Provides bounds-checked access, deep copy, assignment, and size retrieval.
 *
 * @tparam T Type of the elements stored in the array.
 * Features:
 * - Default and parameterized constructors
 * - Copy constructor and assignment operator (deep copy)
 * - Bounds-checked element access (throws std::out_of_range)
 * - size() method to get the number of elements
 * - Destructor to free allocated memory
 */
template <typename T>
class Array 
{
private:
	T* data;
	unsigned int _size;
public:
	//* empty constructor
	Array() : data(nullptr), _size(0) {}
	//* parameterized constructor
	Array(unsigned int n) : data(nullptr), _size(n)
	{
		if (n > 0)
			data = new T[n](); //* init value
	}
	//* copy constructor
	Array(const Array& src) : data(nullptr), _size(src._size)
	{
		if (_size > 0)
		{
			data = new T[_size]();
			for (unsigned int i = 0; i < _size; i++)
				data[i] = src.data[i];
		}
	}
	//* assignment operator=
	Array& operator=(const Array& src)
	{
		if (this != &src)
		{
			delete[] data;
			_size = src._size;
			if (_size > 0)
				data = new T[_size]();
			else
				data = nullptr;
			for (unsigned int i = 0; i < _size; i++)
				data[i] = src.data[i];
		}
		return *this;
	}

	~Array() {
		delete[] data;
	}

	T& operator[](unsigned int index)
	{
		if (index >= _size)
			throw std::out_of_range("Array index out of bounds");
		return data[index];
	}
	const T& operator[] (unsigned int index) const
	{
		if (index >= _size)
			throw std::out_of_range("Array index out of bounds");
		return data[index];
	}

	unsigned int size() const {
		return _size;
	}
};
