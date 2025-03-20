/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 14:17:24 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/03/20 12:50:22 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("NPC_clap_name"), FragTrap(), ScavTrap()
{
	_name = "NPC"; //* diamondtrap private name
	_health = FragTrap::_health;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDMG = FragTrap::_attackDMG;
	std::cout << "\033[1;33mDefault DiamondTrap constructor called\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	_name = name; //* diamondtrap private name
	_health = FragTrap::_health;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDMG = FragTrap::_attackDMG;
	std::cout << "\033[1;36mParametered DiamondTrap constructor called for " << name << "\033[0m" << std::endl;
}

/**
 * @brief Copy constructor of the diamond inheritance class
 * @note With virtual inheritance, you must explicitly call constructor of base class for proper init
 */
DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), FragTrap(src), ScavTrap(src), _name(src._name)
{
	std::cout << "\033[1;33mCopy DiamondTrap constructor called\033[0m" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& src)
{
	std::cout << "\033[1;34mCopy Assignment Operator DiamondTrap called\033[0m" << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src); //* handles base class members
		ScavTrap::operator=(src); //* handles ScavTrap-specific members
		FragTrap::operator=(src); //* handles FragTrap-specific members
		this->_name = src._name;
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

void DiamondTrap::attack(std::string const& target)
{
	ScavTrap::attack(target);
}
