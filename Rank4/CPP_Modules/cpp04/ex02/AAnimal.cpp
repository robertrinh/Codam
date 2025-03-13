/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:40:52 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/13 16:59:03 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Capybara")
{
	std::cout << "\033[1;32mDefault AAnimal constructor called\033[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "\033[1;32mAAnimal Copy constructor called\033[0m" << std::endl;
	this->_type = src._type;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	std::cout << "\033[1;32mAAnimal Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "\033[1;32mAAnimal Destructor Called\033[0m" << std::endl;
}

const std::string &AAnimal::getType() const
{
	return this->_type;
}

void AAnimal::setType(const std::string &type)
{
	this->_type = type;
}

void AAnimal::makeSound() const
{
	std::cout << "\033[1;32m(Silenced AAnimal noises)\033[0m" << std::endl;
}
