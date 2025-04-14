/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/07 18:03:25 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/04/07 18:15:06 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Mark Rutte"), _signed(false), _grade_exec(1), _grade_sign(2)
{
	std::cout << "\033[1;32mDefault Form constructor called\033[0m" << std::endl;
}

Form::Form(const Form& src) : _name(src._name), _signed(src._signed), _grade_exec(src._grade_exec), _grade_sign(src._grade_sign)
{
	std::cout << "\033[1;33mForm Copy constructor called\033[0m" << std::endl;
}

Form& Form::operator=(const Form& src)
{
	std::cout << "\033[1;30mForm Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

Form::~Form()
{
	std::cout << "\033[1;31mForm Destructor Called\033[0m" << std::endl;
}

Form::Form(std::string name, const int _GradeToSign, const int _GradeToExec) : _name(name), _signed(false), _grade_exec(_GradeToExec), _grade_sign(_GradeToSign)
{
	std::cout << "\033[1;32mParametered Form constructor called\033[0m" << std::endl;
	//! check exec and sign values
	
}

const std::string Form::getName() const
{
	return _name;
}

const int Form::getGradeSign() const
{
	return _grade_sign;
}

const int Form::getGradeExec() const
{
	return _grade_exec;
}

bool Form::getSigned() const
{
	return _signed;
}

//! TODO beSigned function
void Form::beSigned(Bureaucrat &bureaucrat)
{
	
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("THROW: Grade too high");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("THROW: Grade too low");
}

//! TODO operator overload
std::ostream &operator<<(std::ostream& out, const Form& src)
{
	return out;
}
