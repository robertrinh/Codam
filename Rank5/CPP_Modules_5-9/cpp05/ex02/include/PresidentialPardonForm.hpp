/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/14 17:19:38 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/04/14 17:22:00 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "../include/AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
	
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& src);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
	~PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);

	void execute(Bureaucrat const& executor) const override;
};
