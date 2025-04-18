/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 13:08:49 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/13 17:23:45 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "\033[1;34mDefault Dog constructor called\033[0m" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "\033[1;34mDog Copy constructor called\033[0m" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "\033[1;34mDog Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
		Animal::operator=(src);
	return *this;
}

Dog::~Dog()
{
	std::cout << "\033[1;34mDog Destructor Called\033[0m" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "\033[1;34m(Aggresive Dog noises)\033[0m" << std::endl;
}
