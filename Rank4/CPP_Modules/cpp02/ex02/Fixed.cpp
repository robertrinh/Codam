/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/24 15:51:52 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/05 13:32:13 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//*Constructors, Copies and destructor (Orthodox Canonical Form)*//
Fixed::Fixed() : _rawValue(0)
{
	std::cout << "\033[1;32mDefault constructor called\033[0m" << std::endl;
}

Fixed::Fixed(const int value) : _rawValue(value << _fractionalBits)
{
	std::cout << "\033[1;30mInt constructor called\033[0m" << std::endl;
}

Fixed::Fixed(const float value) : _rawValue(roundf(1 << _fractionalBits) * value)
{
	std::cout << "\033[1;36mFloat constructor called\033[m" << std::endl;
}

/**
 * @brief Copy constructor
 * @param src takes a const reference to another object of the same class
 * @note creates new object as a copy of an existing project
 */
Fixed::Fixed(const Fixed& src)
{
	std::cout << "\033[1;33mCopy constructor called\033[0m" << std::endl;
	*this = src;
}

/**
 * @brief Copy assignment operator
 * @param src takes a const reference to another object of the same class
 * @return a reference to the current object (to allow assignment chaining) (f.e. obj1 = obj2 = obj3)
 * @note Assigns the value of one object to another with a "deep copy"
 */
Fixed& Fixed::operator=(const Fixed& src)
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


//* Comparison Overload Operators *//

/**
 * @brief checks if the `==` comparison is correct 
 * @param src takes a const reference to another object of the same class
 * @note you can apply the same description to all the other Comparison Overload Operator 
 * @return the comparison which will return true if correct, false if not
 */
bool	Fixed::operator==(const Fixed& src) const
{
	return this->_rawValue == src._rawValue;
}

bool	Fixed::operator!=(const Fixed& src) const
{
	return this->_rawValue != src._rawValue;
}

bool	Fixed::operator<(const Fixed& src) const
{
	return this->_rawValue < src._rawValue;
}

bool	Fixed::operator>(const Fixed& src) const
{
	return this->_rawValue > src._rawValue;
}

bool	Fixed::operator<=(const Fixed& src) const
{
	return this->_rawValue <= src._rawValue;
}

bool	Fixed::operator>=(const Fixed& src) const
{
	return this->_rawValue >= src._rawValue;
}

//* Arithmetic Overload Operators *//
/**
 * @brief overloads the `<<` operator with the `+` arithmetic
 * @param src takes a const reference to another object of the same class
 * @note you can apply the same description to the `-` arithmetic
 * @return The full `Fixed` object that contains the result of the operation
 */
Fixed Fixed::operator+(const Fixed& src) const
{
	Fixed res;
	res.setRawBits(this->_rawValue + src._rawValue);
	return res;
}

Fixed Fixed::operator-(const Fixed& src) const
{
	Fixed res;
	res.setRawBits(this->_rawValue - src._rawValue);
	return res;
}

/**
 * @brief overloads the `<<` operator with the `/` arithmetic
 * @param src takes a const reference to another object of the same class
 * @note you can apply the same description to the `*` arithmetic
 * @details uses toFloat() to convert to fixed point, perform operation, then convert back to fixed-point
 * @return The full `Fixed` object with a converted fixedpoint after the operation
 */
Fixed Fixed::operator/(const Fixed& src) const
{
	return Fixed(this->toFloat() / src.toFloat());
}

Fixed Fixed::operator*(const Fixed& src) const
{
	return Fixed(this->toFloat() * src.toFloat());
}

//* Increment/decrement operators *//
/**
 * @brief performs incrementing operation (++a)
 * @note smallest representable value is 1/256 (2^-8)
 * @note same description for the decrementing operation (--a)
 * @return copy of the object before incrementing
 */
Fixed& Fixed::operator++()
{
	this->_rawValue++;
	return *this;
}

/**
 * @brief perform post incrementing operation (a++)
 * @note same description for the post decrementing operation (a--)
 * @return the unmodified copy
 */
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed& Fixed::operator--()
{
	this->_rawValue--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

//* Overloaded member functions *//
/**
 * @brief takes two references and returns a reference to the smallest one
 * @return ternary operator which evaluates to either a or b
 */
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

/**
 * @brief takes two const references and returns a reference to the smallest one
 * @return ternary operator which evaluates to either a or b, which is a const 
 */
const Fixed& Fixed::min(const Fixed&  a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}


//* Public member functions *//

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
