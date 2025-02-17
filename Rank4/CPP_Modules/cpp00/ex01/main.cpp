/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/10 17:04:54 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/17 18:10:59 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

void show_prompt(void)
{
	std::cout << "\033[1;34mWelcome to the phonebook!\033[0m" << std::endl;
	std::cout << "\033[1;32mThe following commands are available to you:\033[0m" << std::endl;
	std::cout << "\033[1;33mADD: adds a new contact to the phonebook (maximum of 8)\033[0m" << std::endl;
	std::cout << "\033[1;33mSEARCH: search for a contact in the phonebook\033[0m" << std::endl;
	std::cout << "\033[1;33mEXIT: exits the phonebook (beware! you will lost all your contacts!)\033[0m" << std::endl;
}

int main()
{
	Phonebook phonebook;
	std::string input;

	show_prompt();
	while (1)
	{
		std::cout << "\033[1;35mWhat is thyne wish? > \033[0m";
		if (!std::getline(std::cin, input))
		{
			std::cout << "\033[1;31mEOF detected, exiting\033[0m" << std::endl;
			break ;
		}
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input == "EXIT")
		{
			std::cout << "\033[1;32madios amigos!\033[0m" << std::endl;
			break ;
		}
		else
			std::cout << "\033[1;31mSir, we don't have that here\033[0m" << std::endl;
	}
	return 0;
}
