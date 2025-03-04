/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/12 17:26:02 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/03/04 13:25:41 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <sstream>
#include <string>

// constructor
PhoneBook::PhoneBook(void)
{
	this->_size = 0;
	this->_nextsize = 0;
	// std::cout << "Phonebook constructor called" << std::endl;
	return ;
}

// destructor
PhoneBook::~PhoneBook(void)
{
	// std::cout << "Phonebook destructor called" << std::endl;
	return ;
}

/**
 * @brief truncate the string to 9 characters and add a dot
 */
std::string truncate(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + "."); // truncate the string to 9 characters and add a dot
	return (str);
}

// member function van de class Phonebook: syntax with :: operator
void	PhoneBook::displayContacts()
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;

	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < this->_size; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncate(_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncate(_contacts[i].getNickName()) << "|" << std::endl;
	}
}

// member function van de class Phonebook: syntax with :: operator. _getinfo is a private function
void	PhoneBook::_getinfo(std:: string &info, const std::string &prompt)
{
	while (1)
	{
		std::cout << prompt;
		if ((std::getline(std::cin, info) && !info.empty()) || std::cin.eof())
			break ;
		std::cout << "\033[1;31mField must be filled in\033[0m" << std::endl;
	}
}

void	PhoneBook::addSize(Contact& contact)
{
	if (this->_size < 8)
	{
		this->_contacts[this->_size % 8] = contact;
		this->_size++;
	}
	else
	{
		_contacts[_nextsize] = contact;
		_nextsize = (_nextsize + 1) % 8;
		std::cout << std::endl << "\033[1;31mWARNING! Book is full. You are going to overwrite Contact #" << _nextsize - 1 << "!\033[0m" << std::endl;
	}
}

void	PhoneBook::addContact()
{
	std::string input;
	Contact new_contact;

	std::cout << "\033[1;34mPlease get these credentials of the new contact in!!\033[0m" << std::endl;
	_getinfo(input, "\033[1;34mFirst Name: \033[0m");
	new_contact.setFirstName(input);

	_getinfo(input, "\033[1;34mLast Name: \033[0m");
	new_contact.setLastName(input);

	_getinfo(input, "\033[1;34mNickname: \033[0m");
	new_contact.setNickname(input);

	_getinfo(input, "\033[1;34mPhone Number: \033[0m");
	new_contact.setPhoneNumber(input);

	_getinfo(input, "\033[1;34mDarkest Secret: \033[0m");
	new_contact.setDarkestSecret(input);
	
	addSize(new_contact);
	std::cout << "\033[1;32mYou got yourselves a new contact!\033[0m" << std::endl;
}

void	PhoneBook::searchContact()
{
	std::string input;
	Contact contact;
	int	index;

	if (this->_size == 0)
	{
		std::cout << "\033[1;31mAyo.. you got no contacts!! start writing\033[0m" << std::endl;
		return ;
	}
	displayContacts();
	while (1)
	{
		std::cout << "\033[1;34mEnter the index of the contact you want to see: \033[0m";
		if (!std::getline(std::cin, input))
			break ;
		if (input.empty() || !isdigit(input[0]))
		{
			std::cout << "\033[1;31mSir, we don't have that here (give a valid numerical)\033[0m" << std::endl;
			continue ;
		}
		std::istringstream iss(input);
		iss >> index;
		if (index < 0 || index >= this->_size)
		{
			std::cout << "\033[1;31mGive a valid index!\033[0m" << std::endl;
			continue ;
		}
		else
		{
			std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
			std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
			std::cout << "Nickname: " << _contacts[index].getNickName() << std::endl;
			std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
			break ;
		}
	}
}
