/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/07 18:03:25 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/04/14 16:45:15 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Mark Rutte"), _signed(false), _grade_sign(2), _grade_exec(1)
{
	std::cout << "\033[1;32mDefault Form constructor called\033[0m" << std::endl;
	if (_grade_sign < 1 || _grade_exec < 1)
		throw Form::GradeTooHighException();
	else if (_grade_sign > 150 || _grade_exec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& src) : _name(src._name), _signed(src._signed), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec)
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

Form::Form(std::string name, const int _GradeToSign, const int _GradeToExec) : _name(name), _signed(false), _grade_sign(_GradeToSign), _grade_exec(_GradeToExec)
{
	std::cout << "\033[1;32mParametered Form constructor called\033[0m" << std::endl;
	if (_grade_sign < 1 || _grade_exec < 1)
		throw Form::GradeTooHighException();
	else if (_grade_sign > 150 || _grade_exec > 150)
		throw Form::GradeTooLowException();
}

const std::string Form::getName() const
{
	return _name;
}

int Form::getGradeSign() const
{
	return _grade_sign;
}

int Form::getGradeExec() const
{
	return _grade_exec;
}

bool Form::getSigned() const
{
	return _signed;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_grade_sign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return "Error: this form has dream tier formatting, its too high";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return "Error: I've never seen a form this bad? Comic sans?! your grade it too low!";
}

//! TODO operator overload
std::ostream &operator<<(std::ostream& out, const Form& src)
{
	out << "The form in question, mate:\n"
		<< "Name: " << src.getName() << "\n"
		<< "Grade to sign: " << src.getGradeSign() << "\n"
		<< "Grade to execute: " << src.getGradeExec() << "\n"
		<< "Signed: " << (src.getSigned() ? "yeah" : "nah");
	return out;
}
