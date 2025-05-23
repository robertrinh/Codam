#include "ScalarConverter.hpp"

enum class ScalarType
{
	INT,
	CHAR,
	FLOAT,
	DOUBLE,
	INVALID
};

static bool isChar(const std::string& input)
{
	if (input.length() != 1)
		return false;
	return isprint(input.front());
}

static bool isInt(const std::string& input)
{
	if (input.empty())
		return false;
	
	//* if it was passed with quotes, it's not an integer
	if (input[0] == '\'' && input[input.length() - 1] == '\'')
		return false;
	
	try {
		size_t pos;
		long long num = std::stoll(input, &pos);
		if (pos != input.length())
			return false;
		return num >= std::numeric_limits<int>::min() && 
			   num <= std::numeric_limits<int>::max();
	} 
	catch (const std::exception&) {
		return false;
	}
}

static bool isFloat(const std::string& input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return true;
	if (input.empty() || input.back() != 'f')
		return false;
	if (input.find('.') == std::string::npos)
		return false;

	try {
		size_t pos;
		std::stof(input.substr(0, input.length() - 1), &pos);
		return pos == input.length() - 1;
	} 
	catch (const std::exception&) {
		return false;
	}
}

static bool isDouble(const std::string& input)
{
	if (input == "-inf" || input == "+inf" || input == "nan")
		return true;
	if (input.empty())
		return false;

	try {
		size_t pos;
		std::stod(input, &pos);
		return pos == input.length();
	} catch (const std::exception&) {
		return false;
	}
}

static ScalarType detectType(const std::string& input)
{
	if (isInt(input))
		return ScalarType::INT;
	if (isChar(input))
		return ScalarType::CHAR;
	if (isFloat(input))
		return ScalarType::FLOAT;
	if (isDouble(input))
		return ScalarType::DOUBLE;
	return ScalarType::INVALID;
}

static void convertChar(const std::string& input)
{
	const char c = input[0];
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void convertInt(const std::string& input)
{
	try {
		const long long num = std::stoll(input); //* long long to catch overflow
		if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min()) 
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
			return;
		}
		const int i = static_cast<int>(num);
		if (i >= 32 && i <= 126)
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
	} 
	catch (const std::exception&) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

static void convertFloat(const std::string& input)
{
	float f;
	if (input == "-inff") f = -std::numeric_limits<float>::infinity();
	else if (input == "+inff") f = std::numeric_limits<float>::infinity();
	else if (input == "nanf") f = std::numeric_limits<float>::quiet_NaN();
	else {
		try {
			f = std::stof(input.substr(0, input.length() - 1));
		} 
		catch (const std::exception&) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}

	if (f >= 32 && f <= 126 && !std::isnan(f) && !std::isinf(f))
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	if (!std::isnan(f) && !std::isinf(f) && 
		f >= std::numeric_limits<int>::min() && 
		f <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

static void convertDouble(const std::string& input)
{
	double d;
	if (input == "-inf") d = -std::numeric_limits<double>::infinity();
	else if (input == "+inf") d = std::numeric_limits<double>::infinity();
	else if (input == "nan") d = std::numeric_limits<double>::quiet_NaN();
	else {
		try {
			d = std::stod(input);
		} 
		catch (const std::exception&) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}

	if (d >= 32 && d <= 126 && !std::isnan(d) && !std::isinf(d))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	if (!std::isnan(d) && !std::isinf(d) && 
		d >= std::numeric_limits<int>::min() && 
		d <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	if (std::isnan(d))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(d))
		std::cout << "float: " << (d < 0 ? "-inff" : "+inff") << std::endl;
	else if (d >= -std::numeric_limits<float>::max() && 
		d <= std::numeric_limits<float>::max())
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;

	if (std::isnan(d))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(d))
		std::cout << "double: " << (d < 0 ? "-inf" : "+inf") << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

ScalarConverter::ScalarConverter()
{
	std::cout << "\033[1;33mDefault ScalarConverter constructor called\033[0m" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	std::cout << "\033[1;32mScalarConverter Copy constructor called\033[0m" << std::endl;
	(void)src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
	std::cout << "\033[1;30mScalarConverter Copy Assignment Operator called\033[0m" << std::endl;
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "\033[1;31mScalarConverter Destructor Called\033[0m" << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
	if (input.empty())
	{
		std::cout << "Error: Empty input" << std::endl;
		return;
	}
	switch (detectType(input))
	{
		case ScalarType::INT:
			convertInt(input);
			break;
		case ScalarType::CHAR:
			convertChar(input);
			break;
		case ScalarType::FLOAT:
			convertFloat(input);
			break;
		case ScalarType::DOUBLE:
			convertDouble(input);
			break;
		case ScalarType::INVALID:
			std::cout << "Error: Invalid input format" << std::endl;
			break;
	}
}
