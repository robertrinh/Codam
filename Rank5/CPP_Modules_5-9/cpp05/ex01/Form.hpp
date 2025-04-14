/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
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

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _grade_sign;
	const int _grade_exec;

public:
	//* OCF
	Form();
	Form(const Form& src);
	Form& operator=(const Form& src);
	~Form();
	Form(std::string name, const int _grade_sign, const int _grade_exec);

	//* getters
	const std::string getName() const;
	int	getGradeSign() const;
	int	getGradeExec() const;
	bool getSigned() const;

	//* member function
	void beSigned(Bureaucrat &bureaucrat);

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
};

//* overload operator
std::ostream& operator<<(std::ostream &out, const Form& src);

#endif