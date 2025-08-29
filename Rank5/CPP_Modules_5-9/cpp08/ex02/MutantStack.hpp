#pragma once
#include <deque>
#include <stack>
#include <iostream>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack();
	MutantStack(const MutantStack& src);
	MutantStack& operator=(const MutantStack& src);
	~MutantStack();

	typedef typename Container::iterator iterator;
	typedef typename Container::reverse_iterator reverse_iterator;

	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();
};

#include "MutantStack.tpp"