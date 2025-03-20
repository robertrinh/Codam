/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/20 16:46:36 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/20 17:38:07 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "\033[1;32mDefault constructor called\033[0m" << std::endl;
}



Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[1;31mDestructor Called\033[0m" << std::endl;
}

