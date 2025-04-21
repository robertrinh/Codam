/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/14 17:19:38 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/04/21 17:32:03 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include "../include/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
	
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);

	void execute(Bureaucrat const& executor) const override;
};
