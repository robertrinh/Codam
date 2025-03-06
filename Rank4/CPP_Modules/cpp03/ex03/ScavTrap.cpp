/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 17:15:25 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/06 14:09:46 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_name = "NPC";
	_health = 100;
	_energyPoints = 50;
	_attackDMG = 20;
	std::cout << "\033[1;33mDefault ScavTrap constructor called\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string const& name)
{
	_name = name;
	_health = 100;
	_energyPoints = 50;
	_attackDMG = 20;
	std::cout << "\033[1;36mParametered ScavTrap constructor called for " << name << "\033[0m" <<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src)
{
	std::cout << "\033[1;33mCopy ScavTrap constructor called\033[0m" << std::endl;
	*this = src;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "\033[1;34mCopy Assignment Operator ScavTrap called\033[0m" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_health = src._health;
		this->_energyPoints = src._energyPoints;
		this->_attackDMG = src._attackDMG;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[1;31mScavTrap Destructor Called\033[0m" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "You want that restaurant? nah man we booting up the GATEKEEPER MODE" << std::endl;
}
