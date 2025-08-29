#pragma once

#include "MutantStack.hpp"
#include <stdexcept>

//* OCF
//* Constructor
template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{}

//* Copy Constructor
template<typename T, typename Container>
MutantStack<T,Container>::MutantStack(const MutantStack& src) : std::stack<T,Container>(src)
{}

//* Copy assignment operator
template<typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& src)
{
	if (this != &src)
		std::stack<T,Container>::operator=(src);
	return *this;
}

//* Destructor
template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack() 
{}

//* Iterators
template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return this->c.begin(); //* c is protected member variable in std::stack
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return this->c.end();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return this->c.rbegin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend()
{
	return this->c.rend();
}