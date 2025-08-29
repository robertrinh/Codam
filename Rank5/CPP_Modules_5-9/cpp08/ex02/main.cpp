#include "MutantStack.hpp"
#include <list>

int main()
{
	{
	std::cout << "------ FIRST TEST: ITERATOR -----" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top of the stack should be 17: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "17 is popped, size should be 1: " << mstack.size() << std::endl;
	std::cout << "top of the stack should be 5: " << mstack.top() << std::endl;
	std::cout << "pushing 3 - 5 - 737 - 0 to the stack" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "showcasing the iterator" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "Stack iterated: " << *it << std::endl;
		++it;
	}
	}
	{
	std::cout << "\n-----SECOND TEST: REVERSE ITERATOR-----" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top of the stack should be 17: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "17 is popped, size should be 1: " << mstack.size() << std::endl;
	std::cout << "top of the stack should be 5: " << mstack.top() << std::endl;
	std::cout << "pushing 3 - 5 - 737 - 0 to the stack" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "showcasing the reverse iterator" << std::endl;
	MutantStack<int>::reverse_iterator it = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite = mstack.rend();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "Reversed: " << *it << std::endl;
		++it;
	}
	}
	{
	std::cout << "\n-----THIRD TEST: USING STD::LIST-----" << std::endl;
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	mstack.pop_back();
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "std::list iterated with own iterator: " << *it << std::endl;
		++it;
	}
	}
	return 0;
}