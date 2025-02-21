/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/21 12:41:04 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/02/21 13:10:39 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

/**
 * @brief Constructor for HumanA
 * @details after : is the member initializer list
 * @details init's the class member variable before the body constructor executes
 */
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	this->_name = name;
	std::cout << this->_name << " has spawned with a " << this->_weapon.getType() << std::endl;
	return ;
}

HumanA::~HumanA()
{
	std::cout << this->_name << " has fought a battle, only to die" << std::endl;
	return ;
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
