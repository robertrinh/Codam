/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/14 17:47:47 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/05/12 13:20:17 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/AForm.hpp"
#include "./include/Bureaucrat.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/Intern.hpp"

int main()
{
	{
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}
	{
		std::cout << "\n\033[1;35m--- Testing Valid Forms ---\033[0m" << std::endl;
		Intern intern;
		Bureaucrat high("high ranker", 1);
		AForm* form;

		form = intern.makeForm("presidential pardon", "Hunter");
		if (!form)
			return 1;
		high.signAForm(*form);
		high.executeForm(*form);
		delete form;

		std::cout << std::endl;
		form = intern.makeForm("robotomy request", "Claude");
		if (!form)
			return 1;
		high.signAForm(*form);
		high.executeForm(*form);
		delete form;

		std::cout << std::endl;
		form = intern.makeForm("shrubbery creation", "Garden");
		if (!form)
			return 1;
		high.signAForm(*form);
		high.executeForm(*form);
		delete form;
	}

	{
		std::cout << "\n\033[1;35m--- Testing Invalid Form ---\033[0m" << std::endl;
		Intern intern;
		Bureaucrat high("high ranker", 1);
		AForm* form;

		form = intern.makeForm("invalid form", "Mister invalid");
		if (!form)
			return 1;
		high.signAForm(*form);
		high.executeForm(*form);
		delete form;
	}

	return 0;
}