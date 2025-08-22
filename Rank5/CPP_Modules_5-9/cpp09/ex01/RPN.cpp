#include "RPN.hpp"

bool RPN::isOperator(const std::string& token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

void RPN::performOperation(const std::string& op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error: Not enough operands for operation");
	
	int b = _stack.top(); _stack.pop(); //* get value at top, store it in b and then pop it
	int a = _stack.top(); _stack.pop(); //* b first because the second operand is top of the stack
	
	if (op == "+")
		_stack.push(a + b);
	else if (op == "-")
		_stack.push(a - b);
	else if (op == "*")
		_stack.push(a * b);
	else if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Cannot divide by 0, YA HEAR");
		_stack.push(a / b);
	}
}

void RPN::parse_input(const std::string& input)
{
	std::istringstream iss(input);
	std::string token;

	while (iss >> token)
	{
		if (isOperator(token))
			performOperation(token);
		else
		{
			if (token.length() != 1 || !std::isdigit(token[0]))
				throw std::runtime_error("Error: only single digits (0-9) allowed");
			_stack.push(token[0] - '0'); //* ASCII convertion
		}
	}
}

int RPN::rpn_operations(const std::string& input)
{
	try
	{
		parse_input(input);
		if (_stack.size() != 1)
			throw std::runtime_error("Error: Invalid input, try 1 2 +");
		return _stack.top();
	}
	catch (const std::exception& e)
	{
		throw;
	}
}
