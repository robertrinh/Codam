#pragma once

//* ex01 requires LIFO -> Last In First Out
//* stack is good for expression valuation
//* simple operations (pop, push, top) for algorithms
#include <stack>
#include <limits>
#include <iostream>
#include <fstream>
#include <sstream>

class RPN
{
private:
	std::stack<int> _stack;
	bool isOperator(const std::string& token);
	void performOperation(const std::string& op);
	
public:
	RPN() = default;
	RPN(const RPN& src) = delete;
	RPN& operator=(const RPN& src) = delete;
	~RPN() = default;
	
	void parse_input(const std::string& input);
	int rpn_operations(const std::string& input);
};