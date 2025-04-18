/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/04 16:19:24 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/04/14 16:03:01 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
        
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;
        
        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;
        
        Bureaucrat alice("Alice", 151);  // This should throw an exception
        std::cout << "If error is catched, this will not print out" << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& err) {
        std::cout << err.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& err) {
        std::cout << err.what() << std::endl;
    }
    
    std::cout << "\nTrying with maximum grade bureaucrat:" << std::endl;
    try {
        Bureaucrat minister("Dick", 1);
        std::cout << minister << std::endl;
        
        // This will throw an exception because the grade is already at maximum
        minister.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& err) {
        std::cout << err.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& err) {
        std::cout << err.what() << std::endl;
    }
    
    std::cout << "\nTrying with minimum grade bureaucrat:" << std::endl;
    try {
        Bureaucrat minister("Schoof", 150);
        std::cout << minister << std::endl;
        
        minister.decrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& err) {
        std::cout << err.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& err) {
        std::cout << err.what() << std::endl;
    }

    return 0;
}
