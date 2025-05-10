/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/14 17:23:27 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/05/10 15:39:44 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("none yet")
{
	std::cout << "\033[1;32mDefault RobotomyRequestForm constructor called\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src._target)
{
	std::cout << "\033[1;32m RobotomyRequestForm Copy constructor called\033[0m" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	std::cout << "\033[1;30m RobotomyRequestForm Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
		this->_target = src._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[1;31mRobotomyRequestForm Destructor Called\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "\033[1;32mParametered RobotomyRequestForm constructor called\033[0m" << std::endl;
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "DRILLINGS NOIZZZZZZZEZ\nDRILLIN and DRILLIN" << std::endl;
	std::cout << "Believe IN THE ME WHO BELIEVES IN YOU" << std::endl;
	if ((rand() % 2) == 0)
		std::cout << _target << " has been robotomised successfully" << std::endl;
	else
		std::cout << _target << " Robotomy has failed.." << std::endl;
}