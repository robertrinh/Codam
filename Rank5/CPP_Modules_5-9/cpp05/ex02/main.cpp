/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/14 17:47:47 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/05/10 16:04:26 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/AForm.hpp"
#include "./include/Bureaucrat.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/ShrubberyCreationForm.hpp"

int main()
{	
	{
		std::cout << "\n\033[1;35m--- testing Bureaucrat Creation ---\033[0m" << std::endl;
		try {
			Bureaucrat high("high ranker", 1);
			std::cout << "Created: " << high << std::endl;
			
			Bureaucrat low("low ranker", 150);
			std::cout << "Created: " << low << std::endl;
			
			//* should portray exception
			Bureaucrat tooHigh("Snoop dogg", 0);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n\033[1;35m--- testing Form Creation ---\033[0m" << std::endl;
		try {
			ShrubberyCreationForm shrub("Garden");
			std::cout << shrub << std::endl;
			
			RobotomyRequestForm robot("Gemini");
			std::cout << robot << std::endl;
			
			PresidentialPardonForm pardon("Zaphod");
			std::cout << pardon << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n\033[1;35m--- testing Form Signing ---\033[0m" << std::endl;
		try {
			Bureaucrat high("high ranker", 1);
			Bureaucrat low("low ranker", 150);
			
			ShrubberyCreationForm shrub("Garden");
			std::cout << "Before signing: " << shrub << std::endl;
			
			//* should succeed
			high.signAForm(shrub);
			std::cout << "\nAfter signing: " << shrub << std::endl;
			
			//* should fail
			std::cout << std::endl;
			low.signAForm(shrub);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n\033[1;35m--- testing Form Execution ---\033[0m" << std::endl;
		try {
			Bureaucrat high("high ranker", 1);
			Bureaucrat low("low ranker", 150);
			
			//* test Shrubbery Creation
			ShrubberyCreationForm shrub("Garden");
			high.signAForm(shrub);
			high.executeForm(shrub);
			
			//* test Robotomy Request
			std::cout << std::endl;
			RobotomyRequestForm robot("Claude");
			high.signAForm(robot);
			high.executeForm(robot);
			
			//* test Presidential Pardon
			std::cout << std::endl;
			PresidentialPardonForm pardon("Zaphod");
			high.signAForm(pardon);
			high.executeForm(pardon);
			
			//* test execution with low grade
			std::cout << std::endl;
			low.executeForm(shrub);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n\033[1;35m--- testing Unsigned Form Execution ---\033[0m" << std::endl;
		try {
			Bureaucrat high("high ranker", 1);
			
			ShrubberyCreationForm shrub("Garden");
			high.executeForm(shrub); //* execute and not sign
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}