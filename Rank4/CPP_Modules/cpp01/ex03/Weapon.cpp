/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/21 12:29:38 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/02/21 13:19:08 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
	std::cout << "You just crafted a weapon!" << std::endl;
	return ;
}

Weapon::~Weapon()
{
	std::cout << "Your weapon broke!" << std::endl;
	return ;
}

const std::string& Weapon::getType() const
{
	return this->_type;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}