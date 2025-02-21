/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/19 13:33:48 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/21 13:26:31 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	//* Human A always has a weapon, so a reference. A reference cannot be null or reassigned later
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl;
	//* Human B does not always have a weapon, so a pointer. Pointer can be null, later set to weapon and then after null again
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB wasteofskin("Waste of skin");
		wasteofskin.attack();
		club.setType("some other type of club");
		wasteofskin.attack();
	}
	return 0;
}
