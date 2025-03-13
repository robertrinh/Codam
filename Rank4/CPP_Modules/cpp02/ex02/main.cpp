/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/24 16:55:28 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/13 17:47:31 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() 
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
	
		std::cout << b << std::endl;
		
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Own tests:" << std::endl;
	{
		Fixed const a ( Fixed(5.05f) + Fixed(1));
		Fixed const b ( Fixed(5.05f) - Fixed(1));
		Fixed const c ( Fixed(5.05f) * Fixed(2));
		Fixed const d ( Fixed(5.05f) / Fixed(2));
		Fixed const e ( Fixed(5.05f) / Fixed(0));

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "testing +: 5.05 + 1 = " << a << std::endl;
		std::cout << "testing -: 5.05 - 1 = " << b << std::endl;
		std::cout << "testing *: 5.05 * 2 = " << c << std::endl;
		std::cout << "testing /: 5.05 / 2 = " << d << std::endl;
		std::cout << "dividing by 0: 5.05 / 0 = " << e << std::endl;
		
		std::cout << "const min of a and b: " << Fixed::min( a, b) << std::endl;
		std::cout << "const max of a and b: " << Fixed::max( a, b) << std::endl;

		Fixed f (Fixed (1));
		Fixed g (Fixed (1));
		Fixed h (Fixed (3));
		if (a > b)
			std::cout << "Comparison operator >: output should be a: " << a << std::endl;
		if (b < a)
			std::cout << "Comparison operator <: output should be b: " << b << std::endl;
		if (f >= g)
			std::cout << "Comparison operator >=: output should be f: " << f << std::endl;
		if (f <= g)
			std::cout << "Comparison operator <=: output should be g: " << g << std::endl;
		if (f == g)
			std::cout << "Comparison operator ==: output should be 1: " << g << std::endl;
		if (f != h)
			std::cout << "Comparison operator !=: f = 1, h = 3. so not a hit and this text triggers" << std::endl;
	}
	return 0;
}
