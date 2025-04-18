/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:40:52 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/13 16:59:03 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Capybara")
{
	std::cout << "\033[1;32mDefault Animal constructor called\033[0m" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "\033[1;32mAnimal Copy constructor called\033[0m" << std::endl;
	this->_type = src._type;
}

Animal &Animal::operator=(const Animal &src)
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

const std::string &Animal::getType() const
{
	return this->_type;
}

void Animal::setType(const std::string &type)
{
	this->_type = type;
}

void Animal::makeSound() const
{
	std::cout << "\033[1;32m(Silenced Animal noises)\033[0m" << std::endl;
}
