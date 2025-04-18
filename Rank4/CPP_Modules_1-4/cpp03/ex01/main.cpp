/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 13:36:50 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/03/20 13:22:53 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap cuz;
	ScavTrap fam("Blitzcrank");
	ScavTrap lad("Wasteman");
	
	std::cout << "Case checks below:" << std::endl;
	std::cout << std::endl << "\033[1;34m>>Normal banter scenarios<<\033[0m" << std::endl;
	cuz.attack("Emily");
	cuz.takeDamage(5);
	cuz.beRepaired(5);
	cuz.guardGate();
	
	std::cout << std::endl << "\033[1;34m>>When a brother is getting killed<<\033[0m" << std::endl;
	fam.takeDamage(50);
	fam.takeDamage(50);
	fam.takeDamage(1);

	std::cout << std::endl << "\033[1;34m>>Out of energy? SPAMMING REPAIR (but no ClapTrap energy tiers)<<\033[0m" << std::endl;
	for (int i = 0; i < 11; i++)
		lad.beRepaired(8);

	return 0;
}
