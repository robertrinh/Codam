/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 14:55:21 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/11 14:59:38 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "\033[1;32mDefault Brain constructor called\033[0m" << std::endl;
}


Brain::Brain(const Brain& src)
{
	std::cout << "\033[1;32mBrain Copy constructor called\033[0m" << std::endl;
	*this = src;
}

Brain& Brain::operator=(const Brain &src)
{
	std::cout << "\033[1;32mBrain Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "\033[1;32mBrain Destructor Called\033[0m" << std::endl;
}