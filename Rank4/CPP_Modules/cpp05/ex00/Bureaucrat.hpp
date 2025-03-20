/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/20 16:24:15 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/20 17:44:35 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat& operator=(const Bureaucrat& src);
	~Bureaucrat();
	Bureaucrat(std::string name, int grade);
	
	std::string getName();
	int			getGrade();
	void		incrementGrade();
	void		decrementGrade();

	class GradeTooHighException : public std::exception
	{
		private:
			std::string _msg;
		public:
			GradeTooHighException(std::string name);
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		private:
			std::string _msg;
		public:
			GradeTooLowException(std::string name);
			virtual const char *what() const throw();	
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat& src);

#endif