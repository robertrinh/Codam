/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 14:17:24 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/03/06 15:09:19 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	_name = "NPC";
	_health = FragTrap::_health;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDMG = FragTrap::_attackDMG;
	std::cout << "\033[1;33mDefault DiamondTrap constructor called\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name)
{
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_health = FragTrap::_health;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDMG = FragTrap::_attackDMG;
	std::cout << "\033[1;36mParametered DiamondTrap constructor called for " << name << "\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
{
	std::cout << "\033[1;33mCopy DiamondTrap constructor called\033[0m" << std::endl;
	*this = src;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "\033[1;34mCopy Assignment Operator DiamondTrap called\033[0m" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_health = src._health;
		this->_energyPoints = src._energyPoints;
		this->_attackDMG = src._attackDMG;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[1;31mDiamondTrap Destructor Called\033[0m" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Eminem: My name is.. " << this->_name << "    MY (CLAP)NAME IS..." << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}
