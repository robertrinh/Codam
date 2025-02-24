/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/24 15:43:12 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/02/24 17:10:48 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	_rawValue;
	static const int _fractionalBits = 8;

public:
	//* Constructors
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& src);
	Fixed& operator=(const Fixed& src);
	~Fixed();
	
	//* Comparison operators
	bool operator==(const Fixed& src) const;
	bool operator!=(const Fixed& src) const;
	bool operator<(const Fixed& src) const;
	bool operator>(const Fixed& src) const;
	bool operator<=(const Fixed& src) const;
	bool operator>=(const Fixed& src) const;

	//* Arithmetic operators
	Fixed operator+(const Fixed& src) const;
	Fixed operator-(const Fixed& src) const;
	Fixed operator/(const Fixed& src) const;
	Fixed operator*(const Fixed& src) const;

	//* Increment/Decrement operators
	Fixed& operator++(); //Pre-incrementing
	Fixed& operator--(); //Pre-decrementing
	Fixed operator++(int); //Post-incrementing
	Fixed operator--(int); //Post-decrementing
	
	//* overloaded member functions
	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& min(Fixed& const a, Fixed& const b);
	static Fixed& max(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& const a, Fixed& const b);
	
	//* member functions
	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int	toInt() const;
	
};

std::ostream &operator<<(std::ostream &out, const Fixed& src);

#endif