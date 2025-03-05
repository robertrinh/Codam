/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/24 15:08:58 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/05 13:08:37 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//* Orthodox Canonical Form has to be used

/**
 * @brief Default constructor
 * @details Init with default values
 */
Fixed::Fixed() : _rawValue(0)
{
	std::cout << "\033[1;32mDefault constructor called\033[0m" << std::endl;
}

/**
 * @brief Copy constructor
 * @param src takes a const reference to another object of the same class
 * @details creates a new object as a copy of an existing object
 */
Fixed::Fixed(const Fixed& src)
{
	std::cout << "\033[1;33mCopy constructor called\033[0m" << std::endl;
	*this = src;
}

/**
 * @brief Copy assignment operator
 * @param src takes a const reference to another object of the same class
 * @return a reference to the current object (to allow assignment chaining)
 * @details Assigns the value of one object to another
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
