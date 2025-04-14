/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:40:52 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/13 17:26:42 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//* Animal *//
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

void Animal::makeSound() const
{
	std::cout << "\033[1;32m(Silenced Animal noises)\033[0m" << std::endl;
}

//* WrongAnimal *//

WrongAnimal::WrongAnimal() : _type("Not A Capybara")
{
	std::cout << "\033[1;31mDefault WrongAnimal constructor called\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "\033[1;31mWrongAnimal Copy constructor called\033[0m" << std::endl;
	this->_type = src._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "\033[1;31mWrongAnimal Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[1;31mWrongAnimal Destructor Called\033[0m" << std::endl;
}

const std::string &WrongAnimal::getType() const
{
	return this->_type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "\033[1;31m(Angry WrongAnimal noises)\033[0m" << std::endl;
}
