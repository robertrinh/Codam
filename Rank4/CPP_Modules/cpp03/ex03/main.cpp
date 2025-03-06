/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 14:55:06 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/03/06 15:16:37 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap joe("Jover");

	joe.whoAmI();
	joe.attack("Back");
	joe.beRepaired(70);
	joe.takeDamage(100);
	return 0;
}