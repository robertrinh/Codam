/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/07 18:03:25 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/04/14 16:45:15 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm() : _name("Mark Rutte"), _signed(false), _grade_sign(2), _grade_exec(1)
{
	std::cout << "\033[1;32mDefault AForm constructor called\033[0m" << std::endl;
	if (_grade_sign < 1 || _grade_exec < 1)
		throw AForm::GradeTooHighException();
	else if (_grade_sign > 150 || _grade_exec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src._name), _signed(src._signed), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec)
{
	std::cout << "\033[1;33mAForm Copy constructor called\033[0m" << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
	std::cout << "\033[1;30mAForm Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

AForm::~AForm()
{
	std::cout << "\033[1;31mAForm Destructor Called\033[0m" << std::endl;
}

AForm::AForm(std::string name, const int _GradeToSign, const int _GradeToExec) : _name(name), _signed(false), _grade_sign(_GradeToSign), _grade_exec(_GradeToExec)
{
	std::cout << "\033[1;32mParametered AForm constructor called\033[0m" << std::endl;
	if (_grade_sign < 1 || _grade_exec < 1)
		throw AForm::GradeTooHighException();
	else if (_grade_sign > 150 || _grade_exec > 150)
		throw AForm::GradeTooLowException();
}

const std::string AForm::getName() const
{
	return _name;
}

int AForm::getGradeSign() const
{
	return _grade_sign;
}

int AForm::getGradeExec() const
{
	return _grade_exec;
}

bool AForm::getSigned() const
{
	return _signed;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_grade_sign)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	executeAction(); //* derived classes override this function
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return "Error: this form has dream tier formatting, its too high";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return "Error: I've never seen a form this bad? Comic sans?! your grade is too low!";
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return "Error: are you anti-form?! SIGN THA TING";
}

std::ostream &operator<<(std::ostream &out, const AForm &src)
{
	out << "The form in question, mate:\n"
		<< "Name: " << src.getName() << "\n"
		<< "Grade to sign: " << src.getGradeSign() << "\n"
		<< "Grade to execute: " << src.getGradeExec() << "\n"
		<< "Signed: " << (src.getSigned() ? "yeah" : "nah");
	return out;
}