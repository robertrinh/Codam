#pragma once

#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <stdexcept>
#include <cmath>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const& src);
	ScalarConverter& operator=(ScalarConverter const& src);
	~ScalarConverter();

public:
	static void	convert(const std::string& input);
};

