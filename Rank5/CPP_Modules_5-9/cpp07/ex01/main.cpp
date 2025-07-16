#include "iter.hpp"
#include <iostream>
#include <string>

void printInt(int x) {
    std::cout << x << ' ';
}

void printString(const std::string &s) {
    std::cout << s << ' ';
}

void printDouble(double x) {
    std::cout << x << ' ';
}

template <typename T>
void increment(T &x) {
    ++x;
}

int main() {
    //* test with int array
    int arr[] = {1, 2, 3, 4, 5};
    std::size_t len = sizeof(arr) / sizeof(arr[0]);
    std::cout << "[int array] Address: " << static_cast<void*>(arr) << ", Length: " << len << ", Function: printInt\n";
    std::cout << "Original: ";
    iter(arr, len, printInt);
    std::cout << std::endl;

    std::cout << "[int array] Address: " << static_cast<void*>(arr) << ", Length: " << len << ", Function: increment<int>\n";
    iter(arr, len, increment<int>);
    std::cout << "After increment: ";
    iter(arr, len, printInt);
    std::cout << std::endl << std::endl;

    //* test with std::string array
    std::string sarr[] = {"hello", "world", "42"};
    std::size_t slen = sizeof(sarr) / sizeof(sarr[0]);
    std::cout << "[string array] Address: " << static_cast<void*>(sarr) << ", Length: " << slen << ", Function: printString\n";
    std::cout << "Original: ";
    iter(sarr, slen, printString);
    std::cout << std::endl << std::endl;

    //* test with double array 
    double darr[] = {1.1, 2.2, 3.3};
    std::size_t dlen = sizeof(darr) / sizeof(darr[0]);
    std::cout << "[double array] Address: " << static_cast<void*>(darr) << ", Length: " << dlen << ", Function: printDouble\n";
    std::cout << "Original: ";
    iter(darr, dlen, printDouble);
    std::cout << std::endl << std::endl;

    //* test with const array
    const int carr[] = {10, 20, 30};
    std::size_t clen = sizeof(carr) / sizeof(carr[0]);
    std::cout << "[const int array] Address: " << static_cast<const void*>(carr) << ", Length: " << clen << ", Function: printInt\n";
    std::cout << "Original: ";
    iter(carr, clen, printInt);
    std::cout << std::endl << std::endl;

    return 0;
}
