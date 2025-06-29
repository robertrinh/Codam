/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/20 16:46:36 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/05/10 15:52:31 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Mark Rutte"), _grade(2)
{
	std::cout << "\033[1;32mDefault Bureaucrat constructor called\033[0m" << std::endl;
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	std::cout << "\033[1;32mBureaucrat Copy constructor called\033[0m" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << "\033[1;30mBureaucrat Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[1;31mBureaucrat Destructor Called\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "\033[1;32mParametered Bureaucrat constructor called\033[0m" << std::endl;
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

const std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: you can't overachieve, 1 is already the highest";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: are you even trying? this is too low! be more bureaucratic!";
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signAForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &err)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because the grade was too low.." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form) const
{
	form.execute(*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", bureaucrat grade: " << src.getGrade();
	return out;
}
