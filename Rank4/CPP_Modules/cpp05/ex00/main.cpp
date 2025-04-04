/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/04 16:19:24 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/04/04 16:20:08 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    // Try to create a valid bureaucrat
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
        
        // Try to increment and decrement grade
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;
        
        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;
        
        // Try to create an invalid bureaucrat
        Bureaucrat alice("Alice", 151);  // This should throw an exception
        std::cout << "This won't print if an exception is thrown" << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Other exception: " << e.what() << std::endl;
    }
    
    // Try another test case with a grade that's too high
    std::cout << "\nTrying with maximum grade bureaucrat:" << std::endl;
    try {
        Bureaucrat minister("Minister", 1);  // Highest possible grade
        std::cout << minister << std::endl;
        
        // This will throw an exception because the grade is already at maximum
        minister.incrementGrade();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
