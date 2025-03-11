/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:46:23 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/11 15:04:20 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	this->_brain = new Brain;
	std::cout << "\033[1;33mDefault Cat constructor called\033[0m" << std::endl;
}


Cat::Cat(const Cat& src)
{
	std::cout << "\033[1;33mCat Copy constructor called\033[0m" << std::endl;
	*this = src;
}

Cat& Cat::operator=(const Cat &src)
{
	std::cout << "\033[1;33mCat Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain;	
	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "\033[1;33mCat Destructor Called\033[0m" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "\033[1;33m(Muzzled Cat noises)\033[0m" << std::endl;
}
