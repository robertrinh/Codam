/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/24 15:51:52 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/14 14:39:20 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief Default constructor
 * @details Init with default values
 * @details constructor are default initialised, so direct initialisation using `:`
 * @details does assignment (value = 0) and init in 1 step, instead of init and then assign in function
 */
Fixed::Fixed() : _rawValue(0)
{
	std::cout << "\033[1;32mDefault constructor called\033[0m" << std::endl;
}

Fixed::Fixed(const int value) : _rawValue(value << _fractionalBits)
{
	std::cout << "\033[1;30mInt constructor called\033[0m" << std::endl;
}

/**
 * @brief Float constructor
 * @param value takes a float value
 * @details bitshifts 8 bits from integer 1 = 256
 * @details roundf rounds the float to an int for the raw value
 */
Fixed::Fixed(const float value) : _rawValue(roundf(1 << _fractionalBits) * value)
{
	std::cout << "\033[1;36mFloat constructor called\033[m" << std::endl;
}

/**
 * @brief Copy constructor
 * @param src takes a const reference to another object of the same class
 * @details creates a new object as a copy of an existing object
 * @details Focused on initialization
 */
Fixed::Fixed(const Fixed& src) : _rawValue(src._rawValue)
{
	std::cout << "\033[1;33mCopy constructor called\033[0m" << std::endl;
}

/**
 * @brief Copy assignment operator
 * @param src takes a const reference to another object of the same class
 * @return a reference to the current object (to allow assignment chaining)
 * @if checks self-assignment (f.e. cat1 = cat1)
 * @details Assigns the value of one object to another
 * @details Works with already existing objects
 */
Fixed &Fixed::operator=(const Fixed& src)
{
	std::cout << "\033[1;34mCopy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
		this->_rawValue = src._rawValue;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "\033[1;31mDestructor Called\033[0m" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_rawValue = raw;
}


/**
 * @brief function that convert the raw value to a float
 * @details effectively shifts to decimal point 8 places to the left (f.e. 1.11)
 * @return takes the raw value and shifts it by 8 bits (fracBits) to the left
 */
float	Fixed::toFloat() const
{
	return (float)this->_rawValue / (1 << this->_fractionalBits);
}

/**
 * @brief function that convert raw value to an integer
 * @details effectively shifts to integer point 8 places to the right (f.e. 1)
 * @return takes the raw value and shifts it by 8 bits (fracBits) to the right
 */
int	Fixed::toInt() const
{
	return this->_rawValue >> this->_fractionalBits;
}

/**
 * @brief The stream insertion operator
 * @details basically redefining what << will be following the reference from another object
 * @param out takes a const reference to ostream where src will be streamed to
 * @param src takes a const reference to another object of the same class
 * @return the stream reference to allow chaining of stream insertions
 */

std::ostream& operator<<(std::ostream& out, const Fixed& src)
{
	return out << src.toFloat();
}
