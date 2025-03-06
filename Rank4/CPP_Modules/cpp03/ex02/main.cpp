/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 13:53:32 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/03/06 14:05:31 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap one;
	FragTrap two("Bob");
	FragTrap three("Bab");

	two.attack("Bab");

	two.highFivesGuys();
	three.attack("Bob");
	three.attack("target");
	three.beRepaired(5);
	three.attack("target");
	three.takeDamage(100);
	three.takeDamage(5);
	three.takeDamage(5);
	return (0);
}
