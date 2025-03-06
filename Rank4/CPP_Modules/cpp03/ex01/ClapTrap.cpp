/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 15:31:57 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/06 13:41:19 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _health(10), _energyPoints(10), _attackDMG(0)
{
	std::cout << "\033[1;32mDefault constructor called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name): _name(name), _health(10), _energyPoints(10), _attackDMG(0)
{
	std::cout << "\033[1;36mParametered constructor called for " << name << "\033[0m" <<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "\033[1;33mCopy constructor called\033[0m" << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "\033[1;34mCopy Assignment Operator called\033[0m" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_health = src._health;
		this->_energyPoints = src._energyPoints;
		this->_attackDMG = src._attackDMG;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[1;31mDestructor Called\033[0m" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << this->_name << " got no energy for this, let it rest" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " \
	<< this->_attackDMG << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_health == 0 || this->_health < 0)
	{
		std::cout << this->_name << " has been banished into the shadow realm, you can't pull a magic card here" << std::endl;
		return ;
	}
	this->_health -= amount;
	std::cout << "ClapTrap " << this->_name << " has taken " << amount << " points of damage!" << std::endl;
	if (this->_health <= 0)
		std::cout << "ClapTrap " << this->_name << " has been banished into the shadow realm" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << this->_name << " aint got energy for this, let it rest" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is being repaired for " << amount << " hit point(s)" << std::endl;
	this->_health += amount;
	this->_energyPoints -= 1;
}
