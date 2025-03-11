/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:40:52 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/11 13:54:37 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//* Animal *//
Animal::Animal() : _type("Capybara")
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

const std::string& Animal::getType() const
{
	return this->_type;
}

void Animal::makeSound() const
{
	std::cout << "\033[1;32m(Muzzled Animal noises)\033[0m" << std::endl;
}

//* WrongAnimal *//

WrongAnimal::WrongAnimal()
{
	std::cout << "\033[1;32mDefault Animal constructor called\033[0m" << std::endl;
}


WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	std::cout << "\033[1;32mAnimal Copy constructor called\033[0m" << std::endl;
	*this = src;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "\033[1;32mAnimal Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[1;32mAnimal Destructor Called\033[0m" << std::endl;
}

const std::string& WrongAnimal::getType() const
{
	return this->_type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "\033[1;32m(Muzzled WrongAnimal noises)\033[0m" << std::endl;
}