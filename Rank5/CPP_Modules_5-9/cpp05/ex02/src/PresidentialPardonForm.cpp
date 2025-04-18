/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/14 17:23:27 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/04/14 17:30:25 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("none yet")
{
	std::cout << "\033[1;32mDefault PresidentialPardonForm constructor called\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), _target(src._target)
{
	std::cout << "\033[1;32m PresidentialPardonForm Copy constructor called\033[0m" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	std::cout << "\033[1;30m PresidentialPardonForm Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
		this->_target = src._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\033[1;31mPresidentialPardonForm Destructor Called\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << "\033[1;32mParametered PresidentialPardonForm constructor called\033[0m" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << _target << "\033[32m has been pardoned by Zaphod Beeblebrox\033[0m" << std::endl;
}