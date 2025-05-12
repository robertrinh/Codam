/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/10 16:07:42 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/05/10 16:11:23 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AForm;

class Intern
{
public:
	Intern();
	Intern(const Intern& src);
	Intern &operator=(const Intern& src);
	~Intern();
	
	AForm* makeForm(const std::string& name, const std::string& target);
};