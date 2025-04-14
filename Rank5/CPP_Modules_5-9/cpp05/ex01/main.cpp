/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/14 16:02:27 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/04/14 17:01:22 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "-----tests with normal forms-----" << std::endl;
	try {
		Bureaucrat min("Dick", 100);
		Form formA("DEI form", 10, 10);
		Form formB("Complaints form", 100, 120);
		
		std::cout << std::endl;
		min.signForm(formA);
		std::cout << "\n" << formA << std::endl;
		
		std::cout << std::endl;
		min.signForm(formB);
		std::cout << "\n" << formB << std::endl;

		Bureaucrat pres("Schoof", 151);
	}
	catch (std::exception &err) {
		std::cout << err.what() << std::endl;
	}

	std::cout << "\n-----tests with invalid forms-----" << std::endl;
	try {
		Bureaucrat min("Mark", 100);
		Form formA("MKB form", 0, 15);
		
		std::cout << std::endl;
		min.signForm(formA);
		std::cout << "\n" << formA << std::endl;
	}
	catch (std::exception &err) {
		std::cout << err.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat min("Mark", 100);
		Form formB("Toeslagen Form", 5, 151);
		
		std::cout << std::endl;
		min.signForm(formB);
		std::cout << "\n" << formB << std::endl;
	}
	catch (std::exception &err) {
		std::cout << err.what() << std::endl;
	}

	std::cout << "\n-----tests with form with Form member function-----" << std::endl;
	try {
		Bureaucrat pres("Geert", 50);
		Form formA("Questionable Form", 50, 50);
		Form formB("Slightly less questionable form", 1, 1);
		
		std::cout << "\n" << formA << "\n" << std::endl;
		formA.beSigned(pres);
		// pres.signForm(formA);
		formB.beSigned(pres);
		pres.signForm(formB);
		std::cout << "\n" << formB << "\n" << std::endl;
	}
	catch (std::exception &err) {
		std::cout << err.what() << std::endl;
	}
	return 0;
}