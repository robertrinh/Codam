/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:46:23 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/11 13:54:44 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
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
		this->_type = src._type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "\033[1;33mCat Destructor Called\033[0m" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "\033[1;33m(Muzzled Cat noises)\033[0m" << std::endl;
}

//* WrongCat *//

WrongCat::WrongCat()
{
	_type = "Cat";
	std::cout << "\033[1;33mDefault Cat constructor called\033[0m" << std::endl;
}


WrongCat::WrongCat(const WrongCat& src)
{
	std::cout << "\033[1;33mCat Copy constructor called\033[0m" << std::endl;
	*this = src;
}

WrongCat& WrongCat::operator=(const WrongCat &src)
{
	std::cout << "\033[1;33mCat Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "\033[1;33mCat Destructor Called\033[0m" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "\033[1;33m(Muzzled WrongCat noises)\033[0m" << std::endl;
}