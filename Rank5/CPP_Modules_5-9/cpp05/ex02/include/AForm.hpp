/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/07 17:52:47 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/04/14 16:24:10 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _grade_sign;
	const int _grade_exec;

public:
	//* OCF
	AForm();
	AForm(const AForm &src);
	AForm &operator=(const AForm &src);
	~AForm();
	AForm(std::string name, const int _grade_sign, const int _grade_exec);

	//* getters
	const std::string getName() const;
	int getGradeSign() const;
	int getGradeExec() const;
	bool getSigned() const;

	//* member function
	void beSigned(Bureaucrat &bureaucrat);
	void execute(Bureaucrat const& executor) const; //* handles all validations of other forms

	virtual void executeAction() const = 0; //* Derived classes only implement through here

	//* exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

//* overload operator
std::ostream &operator<<(std::ostream &out, const AForm &src);

#endif