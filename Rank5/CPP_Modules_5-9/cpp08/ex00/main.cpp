#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v = {1, 2, 3, 4, 5};
	try {
		std::cout << "testing: finding the value of 3 with std::find in the vector" << std::endl;
		auto it = easyfind(v, 3);
		std::cout << "Found: " << *it << std::endl;
		std::cout << std::endl << "testing: throwing an exception because 42 is not in the vector using std::find" << std::endl;
		it = easyfind(v, 42);	
	} catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}