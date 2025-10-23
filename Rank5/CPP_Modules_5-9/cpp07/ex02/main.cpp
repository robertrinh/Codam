#include "array.hpp"
#include <iostream>

int main()
{
	Array<int> a;
	std::cout << "Default constructed array size: " << a.size() << std::endl;

	Array<int> b(5);
	std::cout << "Parameterized constructed array size: " << b.size() << std::endl;
	for (unsigned int i = 0; i < b.size(); ++i)
		std::cout << "b[" << i << "] = " << b[i] << std::endl;

	for (unsigned int i = 0; i < b.size(); ++i)
		b[i] = i * 10;
	for (unsigned int i = 0; i < b.size(); ++i)
		std::cout << "b[" << i << "] after assignment = " << b[i] << std::endl;

	Array<int> c(b);
	std::cout << "Copy constructed array c from b:" << std::endl;
	for (unsigned int i = 0; i < c.size(); ++i)
		std::cout << "c[" << i << "] = " << c[i] << std::endl;

	Array<int> d;
	d = b;
	std::cout << "Assigned array d from b:" << std::endl;
	for (unsigned int i = 0; i < d.size(); ++i)
		std::cout << "d[" << i << "] = " << d[i] << std::endl;
	try {
		std::cout << "Trying to access b[10]: ";
		std::cout << b[10] << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try {
        std::cout << "Trying to access b[-2]: ";
        std::cout << b[-2] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

	const Array<int>& cref = b;
	std::cout << "Accessing through const reference:" << std::endl;
	for (unsigned int i = 0; i < cref.size(); ++i)
		std::cout << "cref[" << i << "] = " << cref[i] << std::endl;

	return 0;
}