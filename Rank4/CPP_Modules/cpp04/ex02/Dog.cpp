/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 13:08:49 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/13 17:45:25 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal(), _brain(new Brain())
{
	std::cout << "\033[1;34mDefault Dog constructor called\033[0m" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &src) : AAnimal(src), _brain(new Brain(*src._brain)) //* aanimal should be explicitly init in copy construct
{
	std::cout << "\033[1;34mDog Copy constructor called\033[0m" << std::endl;
	this->_type = src._type;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "\033[1;34mDog Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
	{
		AAnimal::operator=(src);
		this->_type = src._type;
		delete this->_brain;				   //* in case of existing brain
		this->_brain = new Brain(*src._brain); //* uses the operator
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "\033[1;34mDog Destructor Called\033[0m" << std::endl;
	delete _brain;
}

void Dog::makeSound() const
{
	std::cout << "\033[1;34m(Aggresive Dog noises)\033[0m" << std::endl;
}

void Dog::setIdeas(int index, const std::string &idea)
{
	if (index >= 0 && index <= 100)
		_brain->setIdea(index, idea);
	else
		std::cerr << "Dont underestimate the mathemathic genius of the dog (between 0-100)" << std::endl;
}

std::string &Dog::getIdeas(int index) const
{
	if (index >= 0 && index <= 100)
		return _brain->getIdea(index);
	else
	{
		std::cerr << "Dont underestimate the mathemathic genius of the dog (between 0-100)" << std::endl;
		static std::string empty;
		empty = "";
		return empty;
	}
}
