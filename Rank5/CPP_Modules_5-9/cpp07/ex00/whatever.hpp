#pragma once

/**
 * Swaps the values of two variables of the same type.
 *
 * @tparam T Type of the variables to swap.
 * @param a Reference to the first variable.
 * @param b Reference to the second variable.
 */
template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T& min(const T &a, const T &b)
{
	return (a < b) ? a : b;
}

template <typename T>
const T& max(const T &a, const T &b)
{
	return (a > b) ? a : b;
}