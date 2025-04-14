/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 15:27:37 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/03/05 17:12:41 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap cuz("Blitzcrank");
	ClapTrap fam("Wall-E");
	ClapTrap lad("Emily");

	std::cout << "Case checks below:" << std::endl;
	std::cout << std::endl << "\033[1;34m>>Normal banter scenarios<<\033[0m" << std::endl;
	cuz.attack("Emily");
	cuz.takeDamage(5);
	cuz.beRepaired(5);
	
	std::cout << std::endl << "\033[1;34m>>When a brother is getting killed<<\033[0m" << std::endl;
	fam.takeDamage(10);
	fam.takeDamage(1);

	std::cout << std::endl << "\033[1;34m>>Out of energy? SPAMMING REPAIR<<\033[0m" << std::endl;
	for (int i = 0; i < 11; i++)
		lad.beRepaired(1);
	
	std::cout << std::endl << "\033[1;34m>>Mass attacks!!!<<\033[0m" << std::endl;
	for (int j = 0; j < 11; j++)
		fam.attack("Emily");

	return 0;
}