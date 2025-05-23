#include "Base.hpp"

Base::~Base() {}

//* generates a random instance of A, B, or C
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

//* identifies the type of object pointed to by p -> prints actual type of object pointed by p
//* dynamic cast returns nullptr in case of fail
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

//* identifies the type of object referenced by p without using pointers
//* dynamic_cast throws bad_cast exception for aliases in case of fail
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