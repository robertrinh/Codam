#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "\033[1;33mDefault Serializer constructor called\033[0m" << std::endl;
}

Serializer::Serializer(const Serializer& src)
{
	std::cout << "\033[1;32mScalarConverter Copy constructor called\033[0m" << std::endl;
	(void)src;
}

Serializer& Serializer::operator=(const Serializer& src)
{
	std::cout << "\033[1;30mScalarConverter Copy Assignment Operator called\033[0m" << std::endl;
	(void)src;
	return *this;
}

Serializer::~Serializer()
{
	std::cout << "\033[1;31mScalarConverter Destructor Called\033[0m" << std::endl;
}

/**
 * @brief Converts a Data pointer to an unsigned integer type uintptr_t
 * @param ptr Pointer to a Data object
 * @return uintptr_t representation of the pointer
 */
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

/**
 * @brief Converts an unsigned integer back to a Data pointer
 * @param raw The uintptr_t value to convert back to a pointer
 * @return Pointer to the original Data object
 */
Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
