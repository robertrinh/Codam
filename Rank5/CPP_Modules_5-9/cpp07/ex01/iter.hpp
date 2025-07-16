#pragma once

#include <cstddef>

/**
 * Applies the function f to each element of the array arr of length len.
 *
 * @tparam T Type of the array elements.
 * @tparam F Callable type (function, functor, or lambda).
 * @param arr Pointer to the first element of the array.
 * @param len Number of elements in the array.
 * @param f   Function to apply to each element.
 */
template <typename T, typename F>
void iter(T *arr, std::size_t len, F f)
{
    for (std::size_t i = 0; i < len; ++i)
        f(arr[i]);
}