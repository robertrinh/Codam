#include "Base.hpp"

Base::~Base() {}

/**
 * @brief Generates a random polymorphic object (A, B, or C)
 * @return Base pointer to randomly created derived class instance
 * @details Uses time-seeded random generation to ensure variety across calls
 */
Base* generate()
{
	Base* out = nullptr;
	//* seed with time + rand to ensure different seeds on multiple calls
	std::srand(std::time(NULL) + std::rand());
	
	//* generate random number between 0 and 2
	int random = std::rand() % 3;
	switch (random) {
		case 0:
			out = new A();
			break;
		case 1:
			out = new B();
			break;
		case 2:
			out = new C();
			break;
	}
	return (out);
}

/**
 * @brief Identifies the actual type of object using dynamic_cast with pointers
 * @param p Base pointer to object whose type needs identification
 * @details Uses dynamic_cast pointer mode - returns nullptr on failed cast
 * @note Demonstrates safe polymorphic downcasting without exceptions
 */
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

/**
 * @brief Identifies the actual type of object using dynamic_cast with references
 * @param p Base reference to object whose type needs identification  
 * @details Uses dynamic_cast reference mode - throws error on failure
 * @note (void) to silence the warning in case dynamic cast is unused
 * @note Demonstrates exception-based polymorphic type checking
 */
void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}