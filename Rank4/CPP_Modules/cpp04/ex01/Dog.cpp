/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 13:08:49 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/11 15:04:39 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	this->_brain = new Brain;
	std::cout << "\033[1;34mDefault Dog constructor called\033[0m" << std::endl;
}


Dog::Dog(const Dog& src)
{
	std::cout << "\033[1;34mDog Copy constructor called\033[0m" << std::endl;
	*this = src;
}

Dog& Dog::operator=(const Dog &src)
{
	std::cout << "\033[1;34mDog Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain;
	}
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "\033[1;34mDog Destructor Called\033[0m" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "\033[1;34m(Muzzled Dog noises)\033[0m" << std::endl;
}
