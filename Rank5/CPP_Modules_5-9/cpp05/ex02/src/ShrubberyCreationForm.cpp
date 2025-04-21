/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/14 17:23:27 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/04/21 17:42:14 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Presidential Pardon Form", 145, 137), _target("none yet")
{
	std::cout << "\033[1;32mDefault ShrubberyCreationForm constructor called\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), _target(src._target)
{
	std::cout << "\033[1;32m ShrubberyCreationForm Copy constructor called\033[0m" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << "\033[1;30m ShrubberyCreationForm Copy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
		this->_target = src._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\033[1;31mShrubberyCreationForm Destructor Called\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Presidential Pardon Form", 145, 137), _target(target)
{
	std::cout << "\033[1;32mParametered ShrubberyCreationForm constructor called\033[0m" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::string filename;
	std::ofstream file;

	filename = _target + "_shrubbery";
	file.open(filename);
	if (!file.is_open())
	{
		std::cerr << "error opening file" << std::endl;
		return ;
	}
	file << " 		 _-_ 		" << std::endl; 
	file << "     /~~   ~~'\' 	" << std::endl;
	file << "  /~~         ~~'\'  " << std::endl;
	file << " {               } " << std::endl;
	file << "  '\'  _-     -_  /  " << std::endl;
	file << "    ~  \\ //  ~ 	" << std::endl;
	file << " _- -   | | _- _ 	" << std::endl;
	file << "   _ -  | |   -_ 	" << std::endl;
	file << "       // \\ 		" << std::endl;
	file << "\n or if you really cheeky, here is: ASCII trees inside it" << std::endl;
	file << std::endl;
	file.close();
}
