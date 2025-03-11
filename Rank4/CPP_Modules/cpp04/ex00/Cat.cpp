/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:46:23 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/11 14:39:48 by qtrinh        ########   odam.nl         */
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
	std::cout << "\033[1;35mDefault WrongCat constructor called\033[0m" << std::endl;
}


WrongCat::WrongCat(const WrongCat& src)
{
	std::cout << "\033[1;35mWrongCat Copy constructor called\033[0m" << std::endl;
	*this = src;
}

WrongCat& WrongCat::operator=(const WrongCat &src)
{
	std::cout << "\033[1;35mWrongCat Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "\033[1;35mWrongCat Destructor Called\033[0m" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "\033[1;35m(Muzzled WrongCat noises)\033[0m" << std::endl;
}