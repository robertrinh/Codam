/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 14:55:06 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/03/18 23:04:09 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap joe("Jover");
	
	std::cout << std::endl << "getting Health of Jover, which is FragTrap(100) -> " << joe.getHealth() << std::endl;
	std::cout << "getting Energy points of Jover, which is ScavTrap(50) -> " << joe.getEnergy() << std::endl;
	std::cout << "getting AttackDamage of Jover, which is FragTrap(30) -> " << joe.getAD() << std::endl;
	
	std::cout << std::endl << "attacks with ScavTrap (which has 30 AD): " << std::endl;
	joe.attack("back");
	
	std::cout << std::endl << "Calling WhoAmI??????????" << std::endl;
	joe.whoAmI();

	std::cout << std::endl << "Health FragTrap(100) Taking damage.." << std::endl;
	joe.takeDamage(11); //! uses ClapTrap member function, so uses ClapTrap member variables, so you'll see clap_name.
	joe.takeDamage(89);
	joe.takeDamage(1);
	return 0;
}