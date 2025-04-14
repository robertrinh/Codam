/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/14 17:19:38 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/04/14 17:22:43 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "../include/AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
	
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& src);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
	~RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);

	void execute(Bureaucrat const& executor) const override;
};
