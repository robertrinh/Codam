/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/12 15:40:43 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/18 14:08:12 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

public:
		Contact(void); //constructor
		~Contact(void); //destructor

		std::string getFirstName() const; // getter function for retrieving information
		void setFirstName(const std::string &first_name); // setter function to iniatialize the information
		
		std::string getLastName() const;
		void setLastName(const std::string &last_name);

		std::string getNickName() const;
		void setNickname(const std::string &nickname);

		std::string getPhoneNumber() const;
		void setPhoneNumber(const std::string &phone_number);
		
		std::string getDarkestSecret() const;
		void setDarkestSecret(const std::string &darkest_secret);
};

#endif