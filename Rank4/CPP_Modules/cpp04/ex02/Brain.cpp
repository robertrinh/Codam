/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 14:55:21 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/13 17:09:47 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : _ideas()
{
	std::cout << "\033[1;35mDefault Brain constructor called\033[0m" << std::endl;
}

Brain::Brain(const Brain& src)
{
	std::cout << "\033[1;35mBrain Copy constructor called\033[0m" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
}

Brain& Brain::operator=(const Brain &src)
{
	std::cout << "\033[1;35mBrain Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "\033[1;35mBrain Destructor Called\033[0m" << std::endl;
}

std::string& Brain::getIdea(int index)
{
	return this->_ideas[index];
}

void Brain::setIdea(int index, const std::string& idea)
{
	this->_ideas[index] = idea;
}
