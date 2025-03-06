/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 14:09:53 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/03/06 15:20:41 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string const &name);
	DiamondTrap(const DiamondTrap &src);
	DiamondTrap &operator=(const DiamondTrap &src);
	~DiamondTrap();

	void whoAmI();
	void attack(std::string const& target);
};
