/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/10 16:12:08 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/05/10 16:44:20 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "\033[1;32mDefault Intern constructor called\033[0m" << std::endl;
}

Intern::Intern(const Intern& src)
{
	std::cout << "\033[1;33mIntern Copy constructor called\033[0m" << std::endl;
	*this = src;
}

Intern& Intern::operator=(const Intern& src)
{
	std::cout << "\033[1;30mIntern Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src) {} //! nothing to assign
	return *this;
}

Intern::~Intern()
{
	std::cout << "\033[1;31mIntern destructor called\033[0m" << std::endl;
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	const std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int formType = -1;

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			formType = i;
			break;
		}
	}
	std::cout << "Intern creates " << name << std::endl;
	switch (formType)
	{
		case 0:
			return new PresidentialPardonForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new ShrubberyCreationForm(target);
		default:
			std::cout << "Error: Form name \"" << name << "\" does not exist" << std::endl;
			return NULL;
	}
}