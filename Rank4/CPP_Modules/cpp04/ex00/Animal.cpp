/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:40:52 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/10 17:45:45 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "\033[1;32mDefault Animal constructor called\033[0m" << std::endl;
}


Animal::Animal(const Animal& src)
{
	std::cout << "\033[1;32mAnimal Copy constructor called\033[0m" << std::endl;
	*this = src;
}

Animal& Animal::operator=(const Animal &src)
{
	std::cout << "\033[1;32mAnimal Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "\033[1;32mAnimal Destructor Called\033[0m" << std::endl;
}

void Animal::makeSound()
{
	std::cout << "\033[1;32mAnimal: AWOOOOOOooooo\033[0m" << std::endl;
}
