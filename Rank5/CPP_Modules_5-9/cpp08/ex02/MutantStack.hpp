#pragma once
#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack();
	MutantStack(const MutantStack& src);
	MutantStack& operator=(const MutantStack& src);
	~MutantStack();

	typedef typename std::deque<T>::iterator iterator;
	iterator begin();
	iterator end();
}

#include "MutantStack.tpp"