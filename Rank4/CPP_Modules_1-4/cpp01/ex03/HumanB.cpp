/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/21 12:50:39 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/02/21 13:23:04 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	this->_name = name;
	std::cout << this->_name << " has spawned" << std::endl;
	return ;
}

HumanB::~HumanB()
{
	std::cout << this->_name << " has fought a battle, only to die" << std::endl;
	return ;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}

void HumanB::attack()
{
	if (!this->_weapon)
		std::cout << this->_name << " has no weapon equipped, he IS DEFENCELESS" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
