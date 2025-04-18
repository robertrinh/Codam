/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/10 17:46:23 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/21 17:09:44 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain())
{
	std::cout << "\033[1;33mDefault Cat constructor called\033[0m" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& src) : Animal(src), _brain(new Brain(*src._brain)) //* animal should be explicitly init in copy construct
{
	std::cout << "\033[1;33mCat Copy constructor called\033[0m" << std::endl;
}

Cat& Cat::operator=(const Cat &src)
{
	std::cout << "\033[1;33mCat Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
		delete this->_brain; //* in case of existing brain
		this->_brain = new Brain(*src._brain); //* uses the operator
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "\033[1;33mCat Destructor Called\033[0m" << std::endl;
	delete _brain;
}

void Cat::makeSound() const
{
	std::cout << "\033[1;33m(Muzzled Cat noises)\033[0m" << std::endl;
}

void Cat::setIdeas(int index, const std::string& idea)
{
	if (index >= 0 && index <= 100)
		_brain->setIdea(index, idea);
	else
		std::cerr << "Dont underestimate the mathemathic genius of the cat (between 0-100)" << std::endl;
}

std::string& Cat::getIdeas(int index) const
{
	if (index >= 0 && index <= 100)
		return _brain->getIdea(index);
	else
	{
		std::cerr << "Dont underestimate the mathemathic genius of the cat (between 0-100)" << std::endl;
		static std::string empty;
		empty = "";
		return empty;
	}
}