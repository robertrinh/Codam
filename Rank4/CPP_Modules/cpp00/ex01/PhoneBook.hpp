/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/12 15:26:11 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/03/04 12:52:19 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook 
{
private:
	Contact _contacts[8];
	int _size;
	int	_nextsize; // _ to indicate that this variable is private

	void	_getinfo(std:: string &info, const std::string &prompt);
public:
	PhoneBook(void); //constructor
	~PhoneBook(void); //destructor
	
	void	addSize(Contact& new_contact);
	void	addContact();
	void	searchContact();
	void	displayContacts();
};

#endif