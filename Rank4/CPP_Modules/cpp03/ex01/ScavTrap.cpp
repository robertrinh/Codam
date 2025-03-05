/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 17:15:25 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/05 18:00:08 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "\033[1;33mDefault ScavTrap constructor called\033[0m" << std::endl;
	_health = 100;
}

ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name)
{
	std::cout << "\033[1;36mParametered ScavTrap constructor called for " << name << "\033[0m" <<std::endl;
}
