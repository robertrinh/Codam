/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 13:36:50 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/03/06 13:42:34 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap one;
	ScavTrap two("Bab");
	two.attack("wwwwooooooooooooo");
	two.guardGate();
	two.attack("target");
	two.takeDamage(5);
	two.beRepaired(5);

	two.attack("target");
	two.takeDamage(5);
	two.takeDamage(110);
	two.takeDamage(5);
	two.takeDamage(5);
	return 0;
}
