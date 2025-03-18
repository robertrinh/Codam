/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 15:27:43 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/18 22:46:05 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string _name;
	int			_health;
	int			_energyPoints;
	int			_attackDMG;

public:
	ClapTrap();
	ClapTrap(std::string const &name);
	ClapTrap(const ClapTrap& src);
	ClapTrap& operator=(const ClapTrap& src);
	~ClapTrap();

	int getHealth();
	int getEnergy();
	int getAD();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif