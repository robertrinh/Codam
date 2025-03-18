/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 17:15:25 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/18 22:11:45 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_name = "NPC";
	_health = 100;
	_energyPoints = 100;
	_attackDMG = 30;
	std::cout << "\033[1;33mDefault FragTrap constructor called\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	_health = 100;
	_energyPoints = 100;
	_attackDMG = 30;
	std::cout << "\033[1;36mParametered FragTrap constructor called for " << name << "\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "\033[1;33mCopy FragTrap constructor called\033[0m" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "\033[1;34mCopy Assignment Operator FragTrap called\033[0m" << std::endl;
	if (this != &src)
		ClapTrap::operator=(src);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[1;31mScavTrap Destructor Called\033[0m" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "Amigo we here on the good vibes gimme a high five brother!" << std::endl;
}
