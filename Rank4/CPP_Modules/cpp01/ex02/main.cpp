/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/18 18:47:39 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/18 19:12:54 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "memory address str: " << &string << std::endl;
	std::cout << "memory address stringPTR: " << stringPTR << std::endl;
	std::cout << "memory address stringREF: " << &stringREF << std::endl;
	
	std::cout << std::endl;
	std::cout << "value of string: " << string << std::endl;
	std::cout << "value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "value of stringREF: " << stringREF << std::endl;

	return 0;
}

//* reference: becomes an alternative name for an existing variable
//* uses & operator
//* if the original variable changes, then the reference will also change
//* when bound to a variable, cannot be changed to a different variable

//* pointer is a variable that stores the memory address of another variable.
//* f.e. pointer to an address on the stack
//* can also be pointing to dynamic memory on the heap
//* dereferencing pointer using * operator to access the actual value