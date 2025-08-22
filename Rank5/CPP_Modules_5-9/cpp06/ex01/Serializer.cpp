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
 * @brief Converts a Data pointer to its memory address as an unsigned integer
 * @param ptr Pointer to a Data object to serialize
 * @return uintptr_t containing the raw memory address of the pointer
 * @details Uses reinterpret_cast to extract pointer's memory address without conversion
 * @details uintptr_t is specifically designed to hold pointer addresses as int
 */
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

/**
 * @brief Converts an unsigned integer back to a Data pointer
 * @param raw The uintptr_t value representing a memory address
 * @return Data pointer reconstructed from the memory address
 * @details Uses reinterpret_cast to convert raw memory address back to typed pointer
 * @warning Undefined behavior if original object was destroyed or address is invalid
 */
Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
