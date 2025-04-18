/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 17:15:32 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/06 13:38:40 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once //* replaces the define guard (ifndef etc.)

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string const& name);
	ScavTrap(const ScavTrap &src);
	ScavTrap& operator=(const ScavTrap& src);
	~ScavTrap();

	void guardGate();
};
