/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/12 17:25:30 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/21 12:19:46 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	// std::cout << "Contact constructor called" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	// std::cout << "Contact destructor called" << std::endl;
	return ;
}

std::string Contact::getFirstName() const {
    return first_name;
}

void Contact::setFirstName(const std::string &first_name) {
    this->first_name = first_name;
}

std::string Contact::getLastName() const {
    return last_name;
}

void Contact::setLastName(const std::string &last_name) {
    this->last_name = last_name;
}

std::string Contact::getNickName() const {
    return nickname;
}

void Contact::setNickname(const std::string &nickname) {
    this->nickname = nickname;
}

std::string Contact::getPhoneNumber() const {
    return phone_number;
}

void Contact::setPhoneNumber(const std::string &phone_number) {
    this->phone_number = phone_number;
}

std::string Contact::getDarkestSecret() const {
    return darkest_secret;
}

void Contact::setDarkestSecret(const std::string &darkest_secret) {
    this->darkest_secret = darkest_secret;
}